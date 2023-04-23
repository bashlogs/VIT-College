data<- read.csv("Expt 1- Dataset_3_pollutant_csv.csv")
m= mean(data$Temp[data$Month==6])
cat("\n\n Mean of temperature when month is 6 : ",m)
n= nrow(data)
cat("\n\n No.of obeservations : ",n)
print(tail(data,2))
oz<- data$Ozone[47]
cat("\n \n Ozone in 47th row :",oz)
ms<-sum(is.na(data$Ozone))
cat("\n\n No. of missng values in Ozone : ",ms)
mn1<- mean(data$Ozone,na.rm = TRUE)
cat("\n\n Mean of ozone column excluding missing values : ",mn1)
ms1<- mean(data$Solar.R[data$Ozone>31 & data$Temp>90],na.rm = TRUE)
cat("\n\n The mean of solar, when ozane values are above 31 and temp values are above 90 : ",ms1)
max<- max(data[data$Month==5,1],na.rm = TRUE)
cat("\n\n The max ozone value in month of may : ",max)




#case study 2 - hair eye color data set----
data2<- read.csv("Expt1-Datset_2_hair_eye_color_csv.csv")
bec<- sum(data2$Eye.Color=="Brown")
cat("\n\n The people having brown eye color are : ",bec)
bhc<- sum(data2$Hair.Color=="Blonde")
cat("\n\n The people having blonde hair color are : ",bhc)
bhc<- sum(data2$Hair.Color=="Blonde")
bbc<- sum(data2$Eye.Color=="Black" & data2$Hair.Color=="Brown")
cat("\n\n  People having brown hair and black eyes :  ", bbc)
ge<- (sum(data2$Eye.Color=="Green")/ nrow(data2))*100
cat("\n\n The percentage of people with Green eyes is ",ge,"%")
rbc<- (sum(data2$Hair.Color=="Red" & data2$Eye.Color=="Blue")/ nrow(data2))*100
cat("\n\n Percentage of people have red hair and Blue eyes is ",rbc,"%")


#case study 3 germination data set ----
data3<- read.csv("Expt1_ Dataset3_germination_csv.csv")
avg<- mean(data3$germinated[data3$Box=="Uncovered" & data3$water_amt==4])
cat("\n\n The average number of seeds germinated for the uncovered boxes with level of watering equal to 4 : ",avg)
med<- median(data3$germinated[data3$Box=="Covered"])
cat("\n\n The median value for the data covered boxes : ", med)


#boxplot - library ggplot 2----
library(ggplot2)
p=ggplot(iris,aes(Sepal.Length,Species,fill=Species)) + geom_boxplot(outlier.color ="red",outlier.shape =4,outlier.size = 4)+theme(legend.position = "none")+coord_flip()+ labs(y = "Species",x = " Sepal Length", title = "Boxplot")
print(p)


#scaterplot ----
library(dslabs)
p1=ggplot(murders,aes(population/10^6,total,label=abb))+geom_point(aes(col= region))+scale_x_log10()+scale_y_log10()+geom_text(size = 2,nudge_x = 0.05)+ labs(x= "POPULATION", y = "TOTAL", title = "SCATTERPLOT")
print(p1)