library(tidyverse)         # For data manipulation and visualization
library(caret)             # For machine learning models
library(ggplot2)           # For plotting graphs
library(reshape2)          # For data manipulation

options(warn=-1)           # Ignore any warnings

train <- read.csv('train.csv')
test <- read.csv('test.csv')

# Inspect the data
colnames(train)
colnames(test)
dim(train)
dim(test)
str(train)
summary(train)

# Plot the distribution of 'age' column
ggplot(train, aes(x=age)) + 
  geom_histogram(binwidth = 5, color="black", fill="white") + 
  labs(title="Distribution of Age", x="Age", y="Frequency")

# Plot the distribution of 'subscribed' column
ggplot(train, aes(x=subscribed)) + 
  geom_bar(stat="count") +
  labs(title="Distribution of Subscribed", x="Subscribed", y="Count")

# Create a correlation matrix plot
corr <- cor(train)
corrplot::corrplot(corr, method="circle", type="lower", tl.col="black")

# Preprocessing
train$subscribed <- ifelse(train$subscribed == "yes", 1, 0)
train_dummies <- train %>% 
  select(-subscribed) %>% 
  dummies::dummy.data.frame()

# Split the data into training and validation sets
set.seed(12)
trainIndex <- createDataPartition(train$subscribed, p=0.8, list=FALSE)
training <- train_dummies[trainIndex,]
validation <- train_dummies[-trainIndex,]

# Fit a logistic regression model
lreg <- train(subscribed~., data=training, method="glm", family="binomial")
lreg_prediction <- predict(lreg, validation)
confusionMatrix(lreg_prediction, validation$subscribed)

# Fit a decision tree model
control <- trainControl(method="repeatedcv", number=10, repeats=3)
model <- train(subscribed~., data=training, method="rpart", trControl=control)
model_prediction <- predict(model, validation)
confusionMatrix(model_prediction, validation$subscribed)

# Predict on test data and write the submission file
test_dummies <- test %>% 
  dummies::dummy.data.frame()
test_prediction <- predict(model, test_dummies)
submission <- data.frame(ID=test$ID, subscribed=test_prediction)
submission$subscribed <- ifelse(submission$subscribed == 1, "yes", "no")
write.csv(submission, "submission.csv", row.names=FALSE)

options(warn=0)             # Reset warning options