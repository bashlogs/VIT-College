data<- read.csv("Expt 3- Dataset_Hypothesis_csv.csv")
#part 1
m<- mean(data$Life_Hrs)
cat(" The observed sample mean is :", m)
sd1<- sd(data$Life_Hrs)
se<- sd1/sqrt(nrow(data))
cat("\n Standard error : ",se)
p1<- pnorm(m,10000,se)
cat("\n p value in 1st case is : ", p1)

if(p1<0.05){
  cat("\n Reject the claim of manufacturer for significance level 0.05")
}else{
  cat("\n The claim of maufacturer for significance level 0.05 is not rejected")
}

if(p1<0.01){
  cat("\n Reject the claim of manufacturer for significance level 0.01")
}else{
  cat("\n The claim of maufacturer for significance level 0.01 is not rejected")
}



#part 2
se2<-17/sqrt(35)
cat("\n\n Standard error is : ",se2)

p2<-2*pnorm(134,130,se2,lower.tail = FALSE)
cat("\n p value for 2nd case is ",p2)

if(p2<0.05){
  cat("\n Null hypothesis to be rejected")
}else{
  cat("\n Null hypothesis  not to rejected")
}

if(p2<0.01){
  cat("\n Null hypothesis to be rejected")
}else{
  cat("\n Null hypothesis not to rejected")
}
