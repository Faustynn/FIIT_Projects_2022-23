package classes.personal;

public class Unior extends Service {
    public Unior(String nameSurname, int age, int salary, String individualLogin, String individualPass,String rank) {
        super(nameSurname, age, 1000,individualLogin,individualPass,"Unior");

    }
    public void editloginUniorEvent(String newLogin) {
        setIndividualLogin(newLogin);
        System.out.println(getNameSurname() + " your new login is " + newLogin);
    }
    public void editpassUniorEvent(String newPass) {
        setIndividualPass(newPass);
        System.out.println(getNameSurname() + " your new password is " + newPass);
    }
}
