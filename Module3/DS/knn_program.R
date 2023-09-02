df<-read.csv("Expt 5-Data Set_knn1_csv.csv")
View(df)
#calculate distance of P=(3,2) from all the points in df
df$eucld_dist<-sqrt((df$x-3)**2+(df$y-2)**2)
View(df)
#
order(df$eucld_dist) #returns row indices of data sorted in ascending order
sorted_data<-df[order(df$eucld_dist),]
View(sorted_data)

# NN
cat("The class of P for NN is:",sorted_data$class[1])

# KNN 
k <- 5
k_neighbours<-sorted_data[1:k,]
View(k_neighbours)
majority_class<-table(k_neighbours$class)
majority_class
knn_class<-names(which.max(majority_class))
cat("The class of P for kNN with K=5:",knn_class)

k <- 7
k_neighbours<-sorted_data[1:k,]
View(k_neighbours)
majority_class<-table(k_neighbours$class)
majority_class
knn_class<-names(which.max(majority_class))
cat("The class of P for kNN with K=7:",knn_class)

k <- 5
k_neighbours$weight=(k_neighbours$eucld_dist[k]-k_neighbours$eucld_dist)/(k_neighbours$eucld_dist[k]-k_neighbours$eucld_dist[1])
View(k_neighbours)
#install.packages("dplyr")
library(dplyr)
df1<-k_neighbours%>%group_by(class)%>%summarise(class_sum=sum(weight))
df1
mknn_class<-df1$class[which.max(df1$class_sum)]
cat("The class of P for mknn is:",mknn_class)

#rnn
r=1.45
r_neighbours<-df[df$eucld_dist<r,]
View(r_neighbours)
t<-table(r_neighbours$class)
rnn_class<-names(which.max(t))
cat("The class of P for rnn is:",rnn_class)


