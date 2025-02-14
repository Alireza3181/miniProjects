public class Person {

    public String username;
    public String password;
    public String type;
    public long money;
    public int verified;

    public Person(String username, String password, String type, long money, int verified)
    {
        this.username = username;
        this.password = password;
        this.type = type;
        this.money = money;
        this.verified = verified;
    }
}
