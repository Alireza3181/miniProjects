import java.util.ArrayList;
import java.util.Iterator;

public class User
{
    private ArrayList<Person> users = new ArrayList<>();
    private ArrayList<Item> items = new ArrayList<>();
    public boolean checkUsername(String username)
    {
        boolean a = false;
        for(Person p : users)
        {
            if (p.username.equals(username))
            {
                a = true;
                break;
            }
        }
        return a;
    }
    public void addUser(Person person)
    {
        users.add(person);
    }
    public boolean checkUser(String username, String password)
    {
        boolean a = false;
        for (Person p : users)
        {
            if (p.username.equals(username) && p.password.equals(password))
            {
                a = true;
                break;
            }
        }
        return a;
    }
    public String findType(String username)
    {
        String t = null;
        for(Person p : users)
        {
            if (p.username.equals(username))
            {
                t = p.type;
            }
        }
        return t;
    }
    public void userInfo(String username)
    {
        for(Person p : users)
        {
            if (p.username.equals(username))
            {
                System.out.println("Username: "+p.username);
                System.out.println("Password: "+p.password);
                if (p.type.equals("c"))
                {
                    System.out.println("User type: Costumer");
                    System.out.println("Balance: "+p.money);
                } else if (p.type.equals("s")) {
                    System.out.println("User type: Seller");
                    if(p.verified==0)
                    System.out.println("Verified status: Not verified");
                    else if (p.verified==1)
                    {
                        System.out.println("Verified status: Verified");
                    }
                }
            }
        }
    }
    public void addBalance(String username, int money)
    {
        for(Person p : users)
        {
            if (p.username.equals(username))
            {
                p.money += money;
                System.out.println("New balance: "+ p.money);
            }
        }
    }
    public void unVerUsers()
    {
        System.out.println("List of unverified costumers: ");
        int i=1;
        for (Person p : users) {
            if (p.type.equals("s") && p.verified == 0) {
                System.out.println(i+"_ "+p.username);
            }
        }
        System.out.println("Available command: 'approve <username>'");
        System.out.println("1. Back");
    }
    public void approveUser(String uap)
    {
        for (Person p : users)
        {
            if (p.username.equals(uap))
            {
                p.verified = 1;
                System.out.println("Done!");
            }
        }
    }
    public void listUsers()
    {
        int i=1;
        for (Person p : users)
        {
            System.out.println(i+"_ Username: "+p.username+" Type: "+p.type);
            i += 1;
        }
    }
    public void delUser(String username)
    {
        int found=0;
        for (Person p : users)
        {
            if (p.username.equals(username))
            {
                users.remove(p);
                System.out.println("User with username \""+p.username+"\" deleted successfully.");
                found = 1;
                break;
            }
        }
        if(found==0)
        {
            System.out.println("No user with username \""+username+"\" found.");
        }
    }
    public void delItem(int ID)
    {
        int found=0;
        for (Item i : items)
        {
            if (i.id == ID)
            {
                items.remove(i);
                System.out.println("Item with ID \""+i.id+"\" deleted successfully.");
                found = 1;
                break;
            }
        }
        if(found==0)
        {
            System.out.println("No item with ID \""+ID+"\" found.");
        }
    }

    public int checkVer(String username)
    {
        for(Person p : users)
        {
            if (p.username.equals(username))
            {
                return p.verified;
            }
        }
        return 3;
    }

    public void addItem(Item item)
    {
        items.add(item);
    }

    public void SdelItem(int ID, String username)
    {
        int found=0;
        for (Item i : items)
        {
            if (i.id == ID)
            {
                if (username.equals(i.owner))
                {
                    items.remove(i);
                    System.out.println("Item with ID \""+i.id+"\" deleted successfully.");
                    found = 1;
                    break;
                }
                else
                {
                    System.out.println("You are not the owner of item with ID \""+i.id+"\".");
                }
            }
        }
        if(found==0)
        {
            System.out.println("No item with ID \""+ID+"\" found.");
        }
    }

    public void listItems()
    {
        int j=1;
        int found=0;
        for (Item i : items)
        {
            System.out.println(j+"_ Item name: "+i.name+" Price: "+i.price+" ID: "+i.id);
            j += 1;
            found += 1;
        }
        if(found == 0)
        {
            System.out.println("No item found");
        }
    }
    public void buyItem(int itm, String username)
    {
        for (Item i : items)
        {
            if (i.id == itm)
            {
                for(Person p : users)
                {
                    if (p.username.equals(username) && (i.price<=p.money) )
                    {
                        p.money -= i.price;
                        items.remove(i);
                        System.out.println("Item bought successfully");
                        System.out.println("New balance: "+p.money);
                    } else if (p.username.equals(username) && (i.price>p.money)) {
                        System.out.println("Sorry you dont have enough balance to buy this item");
                    }
                }
            }
        }
    }
    public void listItemsByTag(String tag)
    {
        int j=1;
        for (Item i : items)
        {
            if (tag.equals(i.tag))
            {
                System.out.println(j+"_ Item name: "+i.name+" Price: "+i.price+" ID: "+i.id);
                j += 1;
            }
        }
        if(j==1)
        {
            System.out.println("No item found with the tag: "+tag);
        }
    }
}
