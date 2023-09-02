library(ggplot2)
theme_set(theme_bw())

data <- read.csv('data.csv')
View(data)
# Draw plot
ggplot(data, aes(x=Date, y=Total)) + 
  geom_bar(stat="identity", width=.5, fill="tomato") + 
  labs(title="Ordered Bar Chart", 
       subtitle="Dates VS Total Stocks", 
       caption="source: mpg") + 
  theme(axis.text.x = element_text(angle=65, vjust=0.6))

library(ggplot2)
library(lubridate)
theme_set(theme_bw())

# read the CSV file
df <- read.csv("data.csv")
head(df)
# subset the data to include only the required columns
df_m <- df[, c("Date", "Total")]

# convert the date column to a date format and extract the month and year information
df_m$Date <- as.Date(df_m$Date, format = "%B %d, %Y")
lbls <- paste0(month.abb[month(df_m$Date)], " ", lubridate::year(df_m$Date))
brks <- df_m$Date

ggplot(df_m, aes(x=Date, y=Total, group=1)) + 
  geom_line() + 
  labs(title="Monthly Time Series", 
       subtitle="Montly Total",
       caption="Source: Data.csv", 
       y="Total Stock Value") +  # title and caption
  scale_x_date(labels = lbls, 
               breaks = brks) +  # change to monthly ticks and labels
  theme(axis.text.x = element_text(angle = 90, vjust=1),  # rotate x axis text
        panel.grid.minor = element_blank())  # turn off minor grid


# Removing Duplicate
data <- unique(data)

# Remove rows with missing data
data <- na.omit(data)

# Fill missing values with a specific value
#data$column[is.na(data$column)] <- value

# Identify and remove outliers











