data<-read.csv("Expt 1- Dataset_3_pollutant_csv.csv")
class(data)
head(data)
dim(data)
structure(data)
tail(data)

# To Remove Null Value
data1<-na.omit(data)

# Mean of a data
mean(data1$Ozone)

# Printing Data
data1

# Dimension of data
dim(data1)

# Printing aleast 2 data
tail(data1,2)

# Printing 47th number
# data(47,Ozone)
data1$Ozone[47]

with(data,boxplot(Temp))

palette()
with(data,boxplot(Temp ~ Month, col = c(1,2,3,4,5)))