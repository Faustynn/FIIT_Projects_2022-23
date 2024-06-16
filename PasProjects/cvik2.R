#'title:"Cvicenie 2"
#'meno:Meredov Nazar
#'datum: 21.02.2024
#'
#'Nastavenie adresata
setwd("") 
getwd() # kontrola nastavenia adresara
# dir() # co je v adresari

# nastavenie kniznic pre latex
library(latexpdf)
library(latex2exp)
library(MASS)
library(PASWR2)
library(ggplot2)

v1<-1:5
v2<-seq(from=1, to=5,by=0.5)
v3<-rep(v2,times=c(1,2,5,3,7,9,4,3,1))
mean(v3) #aritmeticky priemer
sum(v3) #sucet prvkov
length(v3) #kolko je prvkov 
priemer<-sum(v3)/length(v3)
priemer

var(v3) #rozptyl
#cez vzorec
sd(v3)
sd(v3)^2
median(v3)
summary(v3) #sumarna statistika
boxplot(v3,horizontal=TRUE) #kreslime 
hist(v3,xlab="hodnota",ylab="pocet",main = "Nase Data",col = "blue") #vitvarenie histirmamu a ho opis

#kreslenie skupin grafov
par(mfrow=c(2,1)) #kreslime 2 grafa v jednom riadku
hist(v3,xlab="hodnota",ylab="pocet",main = "Nase Data",col = "blue")
boxplot(v3,horizontal=TRUE) 

#kreslenie diskretnych dat
v4<-rep(v1,times=c(2,3,7,4,1))
par(mfrow=c(2,2))
boxplot(v4,horizontal = TRUE,col = "white")
barplot(table(v4),xlab = "hodnota",ylab = "pocet",main = "Diskretne data",col = "green")

hist(v3,xlab="hodnota",ylab="pocet",main = "Nase Data",col = "blue")
boxplot(v3,horizontal=TRUE,col = "pink") 

#kolacovy graf
pie(table(v3),rainbow())