#'title:"Cvicenie 1"
#'meno:Meredov Nazar
#'datum: 14.02.2024
#'
#'Zakladne operacie v R
2+2
3*5
2/8
2^3

#Funkcie a prikazy
sqrt(9)
log(1)
log10(100)
log(8,base=2)
sin(pi/2)
tan(pi/4)

#Faktorial a combinace cislo
factorial(5)
choose(5,2) # 5!/((5-2)!*2!)

#Exponencialna funkcia
exp(2) # e^2
#Priradenie
z<-2+3i
z
#Data type
a<-3
class(a)
b<-4L
class(b)
class(z)
#zMENA DATOVEHO TYPU
d<-as.integer(a)
is.integer(d)
d
#logocky operatory
3>7
5==5
4!=5
#Data struct a vektory
v1<-c(2,3,4)
v2<-c(1,0,2)
v1+v2
v1*v2
v1*c(1,2)
length(v1)
v3<-2:24
v3
v4<-seq(from=2,to=24,by=3)
v4
v5<-rep(v1,times=4)
v5
rep(v1,times=c(3,2,5))
#sucet a sucin prvkov vo vektore
sum(v4)
prod(v1)
sum(v4[3:7])
cumsum(v1)
#Vyber prvku z vektora
v1[1]
v4[7]
v4[3:7]
#Matice
v6<-v3[1:12]
A<-matrix(v6,4,3)
A
#zmena riadkov a stlpcov pri zapise do matize
B<-matrix(v6,4,3,byrow=T)
B
#transponovana matica
t(B)
#vyber prvku z matice 
B[2,3]
#vber podla podmatice
B[1:2,2:3]
#inverzna maica
c<-c(1,2,3,0,1,1,0,0,1)
M<-matrix(c,3,3)
N<-solve(M)
M%*%N

#data frame datovy ramec
meno=c("Alla","Jojo","Nazar","Maria","Pablo","Oleg")
vek=c(14,16,14,18,15,13)
deti=data.frame(meno,vek)
deti
#pridanie neciselneho parametra a pouzitie faktor ktory
deti$polahlove=factor(c(1,0,1,0,0,1),labels = c("m","z"))
deti

#filtrovanie dat
zeny<-subset(deti,deti$polahlove == "z")
zeny
#kombinacia podnienok pre vyber 
subset(deti,deti$polahlove=="z" & deti$test<15)

#Praca s datovom ramcom, hladanie min max sumarna statistica
min(deti$vek)
max(deti$test)
sumary(deti)