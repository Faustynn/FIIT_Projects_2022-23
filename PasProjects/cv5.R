  # Meredov Nazar PAS Cvicenie 5
sum(dbinom(42:54,60,0.8))

pbinom(17,20,0.97)

p<-c(0.3,0.05,0.025,0.375,0.025,0.15,0.15,0,0.2,0.1)
A<-matrix(data=p,3,3,byrow = F)
x<-c(64800,324000,972000)
y<-c(1800,2700,3600)
z<-c(x/y[1],x/y[2],x/y[3])
z

library(tidyverse)
# a}
m<-data.frame(z,p)
m
t(m%>%arrange(z))
