data <- read.csv("Expt 2- Data set_Travelled abroad_csv.csv",header=TRUE)
head(data)

Travel <-(sum(data$Travelledabroad=="Y"))
Travel
cat("\nNumber of people who travel abroad: ",Travel)

Prob <- (Travel/length(data$Travelledabroad))*100
Prob
cat("\nProbability: ",Prob)

p0 <- dbinom(0,10,0.56)
p0
p1 <- dbinom(1,10,0.56)
p1
p2 <- dbinom(2,10,0.56)
p2
p3 <- dbinom(3,10,0.56)
p3
p4 <- dbinom(4,10,0.56)
p4
p5 <- dbinom(5,10,0.56)
p5
p6 <-dbinom(6,10,0.56)
p6
p7 <- dbinom(7,10,0.56)
p7
p8 <- dbinom(8,10,0.56)
p8
p9 <- dbinom(9,10,0.56)
p9
p10 <- dbinom(10,10,0.56)
p10

p <- c(p0,p1,p2,p3,p4,p5,p6,p7,p8,p9,p10)
p <- signif(p,3)

pdf <- data.frame(k=0:10,Probability = p)
pdf

barplot(p,names.arg = c(0,1,2,3,4,5,6,7,8,9,10),col="blue",border="red",main = "Plots: Probabilities of k of n having travelled abroad", ylim=c(0,0.3))
