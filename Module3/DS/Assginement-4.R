library(ggplot2)
library(dplyr)
library(broom)
library(ggpubr)

df=read.csv("Expt 4-Data Set_Toy_sales_csv.csv")

names(df)

r<-lm(formula = Unitsales~ Price+Adexp+Promexp,data=df)
r
pricer = lm(formula = Unitsales~ Price, data = df)
pricer

adexpr = lm(formula = Unitsales~ Adexp, data = df)
adexpr

promexpr = lm(formula = Unitsales~ Promexp, data = df)
promexpr

# iii.	Plot the scatter plot and draw the regression.
scatter.smooth(df$Unitsales~ df$Price+df$Adexp)
scatter.smooth(df$Unitsales~ df$Adexp)
scatter.smooth(df$Unitsales~ df$Promexp)

# iv.	What are values of R-square and residual standard error?
summary(r)
summary(adexpr)
summary(promexpr)
summary(pricer)


linear_model=lm(formula = Unitsales~ Price+Adexp+Promexp,data = df)
Input_variable_Price <- data.frame(Price = c(9.1), Adexp = c(52,000), Promexp = c(61,000))
Input_variable_2 = data.frame(Price = c(8.1), Adexp = c(50,000), Promexp = c(60,000))

predict(linear_model, newdata = Input_variable_2 )