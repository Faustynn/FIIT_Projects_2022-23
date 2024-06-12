package classes.hallclases;

    public class Classic extends Halls {
        // Konstructor pre Classic
        public Classic(double price, int numbofpl,int aktualpl, double expenses, int staffCount) {
            super(price, numbofpl, aktualpl, expenses, staffCount);

        }

        public Classic(){
            super(10, 100,100, 2, 10);
        }

    }
