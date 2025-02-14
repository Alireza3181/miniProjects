using System;
using System.Collections.Generic;

class Program
{
    static void Main()
    {
        Dictionary<int, Account> accounts = new Dictionary<int, Account>();
        int nextAccountId = 1;
        
        while (true)
        {
            Console.WriteLine("\n--- سیستم مدیریت حساب بانکی ---");
            Console.WriteLine("۱- افتتاح حساب");
            Console.WriteLine("۲- واریز به حساب");
            Console.WriteLine("۳- برداشت وجه");
            Console.WriteLine("۴- مشاهده اطلاعات حساب");
            Console.WriteLine("۵- ویرایش اطلاعات حساب");
            Console.WriteLine("۶- خروج از سیستم");
            Console.Write("لطفاً یک گزینه انتخاب کنید: ");

            string choice = Console.ReadLine();
            switch (choice)
            {
                case "1":
                    OpenAccount(accounts, ref nextAccountId);
                    break;
                case "2":
                    Deposit(accounts);
                    break;
                case "3":
                    Withdraw(accounts);
                    break;
                case "4":
                    ViewAccountInfo(accounts);
                    break;
                case "5":
                    EditAccount(accounts);
                    break;
                case "6":
                    Console.WriteLine("خروج از سیستم.");
                    return;
                default:
                    Console.WriteLine("گزینه نامعتبر است.");
                    break;
            }
        }
    }

    static void OpenAccount(Dictionary<int, Account> accounts, ref int nextAccountId)
    {
        Console.Write("نوع حساب (۱- قرض الحسنه، ۲- پس انداز): ");
        string accountType = Console.ReadLine();

        if (accountType != "1" && accountType != "2")
        {
            Console.WriteLine("نوع حساب نامعتبر است.");
            return;
        }

        Console.Write("نام مالک حساب: ");
        string owner = Console.ReadLine();

        accounts[nextAccountId] = new Account
        {
            AccountId = nextAccountId,
            Owner = owner,
            Balance = 0,
            AccountType = accountType == "1" ? "قرض الحسنه" : "پس انداز"
        };

        Console.WriteLine($"حساب با شماره {nextAccountId} با موفقیت ایجاد شد.");
        nextAccountId++;
    }

    static void Deposit(Dictionary<int, Account> accounts)
    {
        Console.Write("شماره حساب: ");
        if (int.TryParse(Console.ReadLine(), out int accountId) && accounts.ContainsKey(accountId))
        {
            Console.Write("مبلغ واریزی: ");
            if (decimal.TryParse(Console.ReadLine(), out decimal amount) && amount > 0)
            {
                accounts[accountId].Balance += amount;
                Console.WriteLine("واریز با موفقیت انجام شد.");
            }
            else
            {
                Console.WriteLine("مبلغ نامعتبر است.");
            }
        }
        else
        {
            Console.WriteLine("شماره حساب نامعتبر است.");
        }
    }

    static void Withdraw(Dictionary<int, Account> accounts)
    {
        Console.Write("شماره حساب: ");
        if (int.TryParse(Console.ReadLine(), out int accountId) && accounts.ContainsKey(accountId))
        {
            Console.Write("مبلغ برداشت: ");
            if (decimal.TryParse(Console.ReadLine(), out decimal amount) && amount > 0)
            {
                if (accounts[accountId].Balance >= amount)
                {
                    accounts[accountId].Balance -= amount;
                    Console.WriteLine("برداشت با موفقیت انجام شد.");
                }
                else
                {
                    Console.WriteLine("موجودی حساب کافی نیست.");
                }
            }
            else
            {
                Console.WriteLine("مبلغ نامعتبر است.");
            }
        }
        else
        {
            Console.WriteLine("شماره حساب نامعتبر است.");
        }
    }

    static void ViewAccountInfo(Dictionary<int, Account> accounts)
    {
        Console.Write("شماره حساب: ");
        if (int.TryParse(Console.ReadLine(), out int accountId) && accounts.ContainsKey(accountId))
        {
            Account account = accounts[accountId];
            Console.WriteLine($"\nاطلاعات حساب:");
            Console.WriteLine($"شماره حساب: {account.AccountId}");
            Console.WriteLine($"مالک حساب: {account.Owner}");
            Console.WriteLine($"نوع حساب: {account.AccountType}");
            Console.WriteLine($"موجودی: {account.Balance}");
        }
        else
        {
            Console.WriteLine("شماره حساب نامعتبر است.");
        }
    }

    static void EditAccount(Dictionary<int, Account> accounts)
    {
        Console.Write("شماره حساب: ");
        if (int.TryParse(Console.ReadLine(), out int accountId) && accounts.ContainsKey(accountId))
        {
            Console.Write("نام جدید مالک حساب: ");
            string newOwner = Console.ReadLine();
            accounts[accountId].Owner = newOwner;
            Console.WriteLine("اطلاعات حساب با موفقیت به روز شد.");
        }
        else
        {
            Console.WriteLine("شماره حساب نامعتبر است.");
        }
    }
}

class Account
{
    public int AccountId { get; set; }
    public string Owner { get; set; }
    public decimal Balance { get; set; }
    public string AccountType { get; set; }
}
