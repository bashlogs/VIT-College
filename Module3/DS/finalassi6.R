library(class)
f1<- read.csv("Expt 6- Dataset_wisconsinn breast cancerdata_csv.csv")
View(f1)
#shuffling the data----
f1$diagnosis<- as.factor(f1$diagnosis)
set.seed(123)
rows<-sample(nrow(f1))
f1<-f1[rows,]
f1_new <- f1[,3:32]
#Normalization for scaling the data between 0 to 1----
n<- function(b){
  (b- min(b))/(max(b)- min(b))
}
f1_nor<- as.data.frame(lapply(f1_new, n))
#splitting data into train and test----
f1_train<- f1_nor[1:469,]
f1_test<- f1_nor[470:569,]
# knn(train data without label , test data without label , train label,k)-
train_label<- f1[1:469,2]
test_label<- f1[470:569,2]
k1<- knn(f1_train,f1_test,train_label,7)
t<- table(actual=test_label,predicted=k1)
print(t)
acc<- sum(diag(t)/sum(t))
cat("\n Accuracy is : ",acc)
sen<- t[2,2]/sum(t[2,])
cat("\n Sensitivity is : ",sen)
spe<- t[1,1]/sum(t[1,])
cat("\n Specificty is : ",spe)
pre<- t[2,2]/sum(t[,2])
cat("\n Precision is : ",pre)