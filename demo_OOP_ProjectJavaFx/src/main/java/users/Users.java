package users;


public class Users {
    private String login;
    private String password;

    private String name;
    private String surname;
    private int age;


    public Users(String login,String password,int age,String name,String surname){
        this.login = login;
        this.password = password;
        this.age = age;
        this.name = name;
        this.surname = surname;
    }

    public Users() {
    }


    public String getLogin(){return login;}
    public void setLogin(String login){this.login =  login;}
    public String getPassword(){return  password;}
    public void setPassword(String rank) {this.password = password;}
    public int getAge(){return  age;}
    public void setAge(int age) {this.age = age;}
    public String getName(){return name;}
    public String getSurname(){return surname;}
    public void setName(String name){this.name = name;}
    public void setSurname(String surname){
        this.surname = surname;
    }
}
