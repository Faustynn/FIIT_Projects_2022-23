#'title:"Cvicenie 3"
#'meno:Meredov Nazar
#'datum: 28.02.2024
#'
library(ggplot2)
library(PASWR2)
library(lattice)

Nationality<-c("German","French","American","Rest of the world")
Year<-c("2003","2004","2005")
tourists<-matrix(c(9.303,9.536,9.918,7.959,7.736,8.875,15.224,15.629,16.09,0.905,0.894,0.883,17.463,18.635,20.148),byrow = TRUE,nrow = 5)
dimnames(tourists)<-list(Nationality,Year)
tourists
tourists[2,2]
tourists[3,]
tourists[,3]

t(apply(tourists,1,sum)) #sucet riadkov dimenzia 1
t(apply(tourists,2,sum)) #sucet riadkov dimenzia 2


# cylkus for
for (name in vektor){
  statement
}

#PRIKLAD spocitaj cisla 10 20 30 a vypis aktualnu hodnotu
sum.a <-0
for(i in c(10,20,30)){
  sum.a <-i+sum.a
  print(sum.a)
}
sum.a

#Priklad 13
for(celsius in seq(18,28,2)){print(c(celsius,9/5*celsius+32))}

#Priklad 4
WHEATUSA2004
sort(WHEATUSA2004$acres) #rozdelenoe dat
quantile(WHEATUSA2004$acres)

quantile(WHEATUSA2004$acres,probs=seq(0,1,0.1))

mean(WHEATUSA2004$acres) #aritmeticky priemer
max(WHEATUSA2004$acres)
min(WHEATUSA2004$acres)
IQR(WHEATUSA2004$acres,0.75) #interkyartilove rozpatie
quantile(WHEATUSA2004$acres,0.75)-quantile(WHEATUSA2004$acres,0.25)
(quantile(WHEATUSA2004$acres,0.75)-quantile(WHEATUSA2004$acres,0.25))/2
var(WHEATUSA2004$acres) #rozpyl
sd(WHEATUSA2004$acres) #standartna odchylka
sum(WHEATUSA2004$acres)/length(WHEATUSA2004$acres) #aritmeticky priemer cez vzorec
summary(WHEATUSA2004$acres) #min max median quartaly a td 
median(WHEATUSA2004$acres) # median



bottom20<-quantile(WHEATUSA2004$acres,probs = 0.20)
bottom20 # pod 20%
WHEATUSA2004[WHEATUSA2004$acres<bottom20,]
top20<-quantile(WHEATUSA2004$acres,probs = 0.80)
top20 #nad 80 %
WHEATUSA2004[WHEATUSA2004$acres>top20,]

WHEATUSA2004[oder(WHEATUSA2004$acres>),]

which(WHEATUSA2004[oder(WHEATUSA2004$acres>),]$states=="WI")
length(WHEATUSA2004$acres) #dlzka vektora
pk<-(9-1)/(30-1)
pk
quntile(WHEATUSA2004$acres,probs=pk)



p1 <- ggplot(WHEATUSA2004,aes(x=acres)) + geom_histogram() +theme_bw()
p2 <-ggplot(WHEATUSA2004,aes(x=acres,y=..destiny..))+ geom_histogram()+geom_density() +theme_bw()
multiplot(p1,p2)
  
p2 <- ggplot(WHEATUSA2004,aes(x=acres,y=..density..))+ geom_histogram(fill = "green")+ geom_density(color="darkred",linewidth =1)+theme_bw()
p2

p2+geom_vline(xintercept = c(median(WHEATUSA2004$acres),mean(WHEATUSA2004$acres))) + annotate("text",label="median",x=median(WHEATUSA2004$acres),y=0.0012)
p2



boxplot(WHEATUSA2004$acres)
boxplot(WHEATUSA2004$acres,horizontal = T)

a<-boxplot.stats(WHEATUSA2004$acres)$out
a
WHEATUSA2004[WHEATUSA2004$acres %in% a,]

noKS<-WHEATUSA2004[-9,]
noKS
mean(WHEATUSA2004$acres)
mean(noKS$acres)
median(WHEATUSA2004$acres)
median(noKS$acres)
var(WHEATUSA2004$acres)
var(noKS$acres)
sd(WHEATUSA2004$acres)
sd(noKS$acres)



VIT2005

VIT2005$out<-factor(VIT2005$out,level=c("E25","E50","E75","E100"))
levels(VIT2005$out)
xtabs(~out,data=VIT2005)

par(mfrow=c(1,2))
barplot(table(VIT2005$out))
pie(table(VIT2005$out))
par(mfrow=c(1,1))

pie(table(VIT2005$out))



p1<-ggplot(data=VIT2005,aes(x=area,y=totalprice))+geom_point() +theme_bw()
p2<-boxplot(VIT2005$area)
multiplot(p1,p2)















