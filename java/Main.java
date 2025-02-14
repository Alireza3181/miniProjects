import java.sql.SQLOutput;
import java.util.Arrays;
import java.util.Scanner;

public class Main
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        User user = new User();

        int input = 0;
        int money = 0;
        int verified = 0;
        int itemId = 1;

        ///////////// admin and default users \\\\\\\\\\\\\\

        user.addUser(new Person("admin", "admin", "admin", 0, 0));
        user.addUser(new Person("c", "c", "c", 1000, 0));
        user.addUser(new Person("s", "s", "s", 0, 1));

        System.out.println("Hello, welcome to our online shop");

        boolean b = true;

        while(b)
        {
            /////////////////////// main menu \\\\\\\\\\\\\\\\\\\\\\\\\

            System.out.println("here's a list of available commands:");
            System.out.println("1. Sign up");
            System.out.println("2. Log in");
            System.out.println("3. Close");

            input = scanner.nextInt();

            switch (input)
            {
                //////////////////// Sign in \\\\\\\\\\\\\\\\\\\\\\\\

                case 1:
                    System.out.print("Seller or costumer?(s or c): ");
                    String type = scanner.next();
                    if(type.equals("1"))
                    {
                        break;
                    }
                    else if (type.equals("s")|| type.equals("c"))
                    {
                        System.out.print("username: ");
                        String username = scanner.next();
                        // checking username
                        if (user.checkUsername(username))
                        {
                            System.out.println("Sorry, this username has already been chosen!");
                            System.out.println("1. Back");
                            int back = scanner.nextInt();
                            if (back == 1)
                            {
                                break;
                            }
                        }
                        else
                        {
                            System.out.print("Password: ");
                            String password = scanner.next();
                            Person person = new Person(username, password, type, money, verified);

                            // adding to users list
                            user.addUser(person);
                            System.out.println("Done!");
                            System.out.println("1. Back");
                            int back = scanner.nextInt();
                            if (back == 1)
                            {
                                break;
                            }
                        }
                    }
                    else
                    {
                        System.out.println("Not a valid type");
                        System.out.println("1. Back");
                        int back = scanner.nextInt();
                        if (back == 1) break;
                    }

                    ///////////////////// log in \\\\\\\\\\\\\\\\\\\\\\\\

                case 2:
                    System.out.print("username: ");
                    String username = scanner.next();
                    System.out.print("password: ");
                    String password = scanner.next();

                    // check user
                    if(!user.checkUser(username, password))
                    {
                        System.out.println("Username or password is wrong!");
                        System.out.println("1. Back");
                        int back = scanner.nextInt();
                        if (back == 1) break;
                    }
                    else
                    {
                        //////////////////// costumer \\\\\\\\\\\\\\\\\\\\\

                        if(user.findType(username).equals("c"))
                        {
                            boolean d = true;
                            while(d)
                            {
                                System.out.println("here's a list of available commands:");
                                System.out.println("1. Account info");
                                System.out.println("2. Add balance");
                                System.out.println("3. List of items");
                                System.out.println("4. Search by tag");
                                System.out.println("5. Log out");
                                input = scanner.nextInt();
                                switch (input)
                                {
                                    //////////////Account info\\\\\\\\\\\
                                    case 1:
                                        user.userInfo(username);
                                        System.out.println("1. Back");
                                        int back = scanner.nextInt();
                                        if (back == 1) continue;

                                    ////////////////Add balance\\\\\\\\\\\\\\\\
                                    case 2:
                                        System.out.print("Amount of money to add: ");
                                        int m = scanner.nextInt();
                                        user.addBalance(username,m);
                                        System.out.println("1. Back");
                                        back = scanner.nextInt();
                                        if (back == 1) continue;

                                    /////////////List of items\\\\\\\\\\\\\\\\\
                                    case 3:
                                        user.listItems();
                                        System.out.println("Available command: 'buy <item id>'");
                                        String command = scanner.next();
                                        if (command.equals("buy")) {
                                            int itemI = scanner.nextInt();
                                            user.buyItem(itemI,username);
                                        } else {
                                            System.out.println("Invalid command.");
                                        }
                                        System.out.println("1. Back");
                                        back = scanner.nextInt();
                                        if (back == 1) continue;

                                   ////////////////////Search by tag\\\\\\\\\\\\\\\\\\\\
                                    case 4:
                                        System.out.print("Enter a tag to search: ");
                                        String Itag = scanner.next();
                                        user.listItemsByTag(Itag);
                                        System.out.println("1. Back");
                                        back = scanner.nextInt();
                                        if (back == 1) continue;

                                    //Log out
                                    case 5:
                                        d = false;
                                        break;

                                }

                            }
                        }

                        ////////////////////// seller\\\\\\\\\\\\\\\\\\\\\\\\

                        else if (user.findType(username).equals("s"))
                        {
                            boolean d = true;
                            while(d)
                            {
                                System.out.println("here's a list of available commands:");
                                System.out.println("1. Account info");
                                System.out.println("2. Add item");
                                System.out.println("3. Remove item");
                                System.out.println("4. Log out");
                                input = scanner.nextInt();
                                switch (input)
                                {
                                    ///////////////////Account info\\\\\\\\\\\\\\\\
                                    case 1:
                                        user.userInfo(username);
                                        System.out.println("1. Back");
                                        int back = scanner.nextInt();
                                        if (back == 1) continue;

                                    /////////////////Add item\\\\\\\\\\\\\\\\\
                                    case 2:
                                        if(user.checkVer(username)==0)
                                        {
                                            System.out.println("This user is not verified by admin.");
                                            System.out.println("1. Back");
                                            back = scanner.nextInt();
                                            if (back == 1) continue;
                                        }
                                        else if (user.checkVer(username)==1)
                                        {
                                            System.out.print("Name: ");
                                            String name = scanner.next();
                                            System.out.print("tag: ");
                                            String tag = scanner.next();
                                            System.out.print("Price: ");
                                            long price = scanner.nextLong();
                                            Item item = new Item(name, tag, price, itemId, username);
                                            user.addItem(item);
                                            System.out.println("Item added successfully");
                                            itemId += 1;
                                            System.out.println("1. Back");
                                            back = scanner.nextInt();
                                            if (back == 1) continue;
                                        }

                                    //////////////////Remove item\\\\\\\\\\\\\\\\\\\\
                                    case 3:
                                        user.listItems();
                                        System.out.print("Insert the item ID to delete: ");
                                        int i = scanner.nextInt();
                                        user.SdelItem(i,username);
                                        System.out.println("1. Back");
                                        back = scanner.nextInt();
                                        if (back == 1) continue;

                                    //Log out
                                    case 4:
                                        d = false;
                                        break;

                                }
                            }
                        }

                        /////////////////////// admin \\\\\\\\\\\\\\\\\\\\\\\\\

                        else if (user.findType(username).equals("admin"))
                        {
                            boolean d = true;
                            while(d)
                            {
                                System.out.println("here's a list of available commands:");
                                System.out.println("1. List of unverified costumers");
                                System.out.println("2. List of all users");
                                System.out.println("3. Remove user");
                                System.out.println("4. Remove item");
                                System.out.println("5. Log out");

                                input = scanner.nextInt();
                                switch (input) {

                                    /////////////////List of unverified costumers\\\\\\\\\\\
                                    case 1:
                                        user.unVerUsers();
                                        String command = scanner.next();
                                        if (command.equals("approve")) {
                                            String uname = scanner.next();
                                            user.approveUser(uname);
                                        } else if (command.equals("1")) {
                                            continue;
                                        } else {
                                            System.out.println("Invalid command.");
                                        }
                                        System.out.println("1. Back");
                                        int back = scanner.nextInt();
                                        if (back == 1) continue;

                                    /////////////////List of all users\\\\\\\\\\\\\\
                                    case 2:
                                        user.listUsers();
                                        System.out.println("1. Back");
                                        back = scanner.nextInt();
                                        if (back == 1) continue;

                                    ///////////////////Remove user\\\\\\\\\\\\\
                                    case 3:
                                        System.out.print("Insert a username to delete: ");
                                        String u = scanner.next();
                                        user.delUser(u);
                                        System.out.println("1. Back");
                                        back = scanner.nextInt();
                                        if (back == 1) continue;

                                    //////////////////Remove item\\\\\\\\\\\\\\
                                    case 4:
                                        user.listItems();
                                        System.out.print("Insert the item ID to delete: ");
                                        int i = scanner.nextInt();
                                        user.delItem(i);
                                        System.out.println("1. Back");
                                        back = scanner.nextInt();
                                        if (back == 1) continue;

                                    //Log out
                                    case 5:
                                        d = false;
                                        break;
                                }
                            }
                        }
                        continue;
                    }

                    // close
                case 3:
                    b = false;
                    System.out.println("Goodbye!");
                    break;
            }
        }
    }
}