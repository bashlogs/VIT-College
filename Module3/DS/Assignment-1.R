# List
v1<-c(100,200,400)
m<-matrix(1:4,2,2)
s<-c("pqr","xyz")

ls<-list(v1,m,s)
ls$spec_chara<-c("@","$")
ls

# Subset
# Only selected will run

#subset<-ls[c(2)]
#subset

# Data Frame

v1 = c(100,200,400)
s<-c("pqr","xyz","abc")
df<-data.frame(v1,s)

names(df)<-c("Physics","Student_address")
rownames(df)<-c("Pawan","Rohan","aachal")
r1<-c(400,500,600)
s1<-c(11,12,13)

df<-cbind(df,r1)
df<-rbind(df,s1)
df

row.names(df)[4]<-c("Mayur")


r2<-c(300,"Mayur",344)
df<-rbind(df,r2)

row.names(df)[5]<-c("Rohit")
df

match_stat<-data.frame(name=c("Tendulkar","Ponting","kallis","Dravid","cook"),
matches=c(200,168,166,164,161),
innings=c(329,287,280,286,291),
highestscore=c(248,257,224,270,294),
avg=c(53.78,51.85,55.37,52.31,45.35))

match_stat
str(match_stat)
summary(match_stat)
dim(match_stat)
head(match_stat)
duplicated(match_stat)
unique(match_stat)
tail(match_stat)
order(match_stat)

