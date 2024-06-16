library(PASWR2)
library(moments)
# 1
with(data = WHEATSPAIN,c(mean(hectares),median(hectares),mad(hectares,constant = 1)))
boxplot(WHEATSPAIN&hectares,horizontal=T)
skewness(WHEATSPAIN&hectares)
# 2
NCL <- subset(WHEATSPAIN,subset=community !="Castilla-Leon")
with(data=NCL,c(mean(hectares),median(hectares),mad(hectares,constant = 1)))
boxplot(NCL&hectares,horizontal=T)
skewness(NCL&hectares)

#T1=(X1+2X2+X3)/4 T2=(X1+X2+X3)/3  -> x je nahodny vyber N(u,sigma^2) ответ сфоткал 

