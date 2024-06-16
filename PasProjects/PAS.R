# mode() returns the mode of an object
# class() returns the class of an object
# prop . table ( table ( NAME ) ) == table ( Grades ) /length ( Grades )

 result1 = (7-8)+ 5^3 - 5 / 6 + sqrt(62)
 result = log(3)+sqrt(2)*sin(pi)-exp(3)
 
 round(result,digits = 3);
 
 countby<-seq(from =5, to=100,by=5)
 Teat<- c(rep("One",20),rep("Two",18),rep("Three",22))
 xtabs(~Teat)
 
 rep(seq(from = 20, to = 5, by = -5), 1:4)
 
 u<-c(1,2,5,4)
 v<-c(2,2,1,1)
 
 which(u==5)  # узнаем индекс
 which(v>=2)
 z<- u * c
 u * (c(u,v))
 
 G <- 1:10
 G[1:3]
 
 J <- seq(from = 1, to = 30, by = 2)
 J[c(1, 3, 8)]
 
 q <- c(3, 0, 1, 6)
 r <- c(1, 0, 2, 4)
 q %*% r

M <- rbind(q,r)
X <- cbind(q,r)

W<-M %*% X
W
t(W)
W


k=0
if(VIT2005$totalprice >=400000 & VIT2005$garage >=1){
  k=k+1
}
k

dim(VIT2005[VIT2005$totalprice >=400000 & VIT2005$garage >=1, ]) # подсчитываем под критерии колво столбцов и рядкой а также выписываем сразу рядок и столбцы
dim(VIT2005[VIT2005$totalprice >=400000 & VIT2005$garage >=1, ])[1]



community<- c("Galicica", "Asturias", "Cantabria", "Pais Vasco", "Navarra", 
              "La Rioja", "Aragon", "Cataluna", "Islas Baleares", 
              "Castilla y Leon", "Madrid", "Castilla-La Mancha",
              "C. Valenciana", "Region de Murcia", "Extremadura",
              "Andalucia", "Islas Canarias")
wheat.surface<- c(18817, 65, 440, 25143, 66326, 34214, 311479, 74206, 7203,
                  619858, 13118, 263424, 6111, 9500, 143250, 558292, 100)

dataframe<- data.frame(community,wheat.surface) # вводим кологки
min(dataframe$wheat.surfac);
max(dataframe$wheat.surfac);
diff(range(dataframe$wheat.surface));


sort <- dataframe[order(dataframe$wheat.surface, decreasing = FALSE), ] # сортирофка в порядке возврастания
head(sort)

wheat.c <- dataframe[dataframe$community != "Asturias", ]
head(wheat.c)

wheat.c$arc<-wheat.surface/0.40468564224
numer<- sum(wheat.c$arc)
numer
numer1 <- sum(wheat.c$wheat.sufrace)
numer1


mean(dataframe$wheat.surface) # средние значение 
head(dataframe) #отображение начальных строк данних
apply(name,1,sum) # используется для применения функции к матрице или массиву вдоль указанного измерения. 1 строка 2 столбец
dumb(namefile,newfile) # create new file and write all to them
rm(namefile) # delete file in R
tail(x,n=5) # print 5 LAST stroke in arr 










