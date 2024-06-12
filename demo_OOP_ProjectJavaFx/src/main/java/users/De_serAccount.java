package users;

public class De_serAccount  implements UniversalAccount{
    private String username;
    private String password;
    private String firstName;
    private String lastName;
    private int age;
    private int id;
    private int score;

    @Override
    public int getAge() {
        return age;
    }

    @Override
    public int getId() {
        return id;
    }
    @Override
    public int getScore() {
        return score;
    }
    @Override
    public String getFirstName() {
        return firstName;
    }
    @Override
    public String getLastName() {
        return lastName;
    }
    @Override
    public String getPassword() {
        return password;
    }
    @Override
    public String getUsername() {
        return username;
    }
    @Override
    public void setUsername(String name) {
        this.username = name;
    }
    @Override
    public void setPassword(String pass) {
        this.password = pass;
    }
    @Override
    public void setFirstName(String firstname) {
        this.firstName = firstname;
    }
    @Override
    public void setLastName(String lastName) {
        this.lastName = lastName;
    }
    @Override
    public void setAge(int age) {
        this.age = age;
    }
    @Override
    public void setId(int id) {
        this.id = id;
    }
    @Override
    public void setScore(int score) {
        this.score = score;
    }
}
