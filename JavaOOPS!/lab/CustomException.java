import java.util.Scanner;
class insufficient_fundsException extends Exception{
    public insufficient_fundsException(){
        super();
    }
}
class invalid_AmmoutException extends Exception{
    public invalid_AmmoutException() {
        super();
    }
}
class Custom_Exception {
    public void accounts(int n, String[] Names, int[] accNumber, int[] amount) {
        Scanner scan = new Scanner(System.in);

        for (int i =0; i< n; i++){
            System.out.print("Enter Customer Name: ");
            Names[i] = scan.next();
            System.out.print("Enter Account Number: ");
            accNumber[i] = scan.nextInt();
            System.out.print("Enter Balance: ");
            amount[i] = scan.nextInt();
            System.out.print("\n");
        }

    }
    public void display(int n, String[] Names, int[] accNumber, int[] amount){
        for(int i =0; i<n; i++){
            System.out.print("Account Name: "+ Names[i]+ "-> Account Number: "+ accNumber[i] + "-> Account Balance: "+ amount[i] + "\n");
        }
    }
    public void search(int n, String[] Names, int[] accNumber, int[] amount){
        int acno, pos = 0;
        boolean flag = false;
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter Account Number: ");
        acno = scan.nextInt();
        for(int i =0; i<n; i++){
            if(accNumber[i] == acno){
                flag = true;
                pos = i;
                break;
            }
        }
        if(flag){
            System.out.print("Account Name: " + Names[pos] + "-> Account Number: " + accNumber[pos] + "-> Account Balance: "+ amount[pos] + "\n");
        }
        else{
            System.out.println("Account not found");
        }
    }
    public void deposit(int n, int[] accNumber, int[] amount){
        int acno, pos = 0, balance;
        boolean flag = false;
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter Account Number: ");
        acno =  scan.nextInt();
        for(int i =0; i<n; i++){
            if(accNumber[i]== acno){
                flag = true;
                pos = i;
                break;
            }
        }
        if(flag){
            System.out.print("Enter amount to be deposited: ");
            balance = scan.nextInt();
            try{
                if (balance <= 0){
                    throw new invalid_AmmoutException();
                }
                else{
                    amount[pos] += balance;
                }
            }
            catch(invalid_AmmoutException e){
            System.out.println("Invalid Amount");
            }
        }
        else{
            System.out.println("Account not found");
        }
    }
    public void withdraw(int n, int[] accNumber, int[] amount){
        int acno, withdraw;
        boolean flag = true;
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter Account Number: ");
        acno = scan.nextInt();
        for(int i = 0; i<n;i++){
            if(accNumber[i] == acno){
                flag = false;
                System.out.print("Enter amount to be Withdrawn");
                withdraw = scan.nextInt();
                try{
                    if(withdraw <= 0){
                        throw new invalid_AmmoutException();
                    }
                    else if(withdraw>amount[i]){
                        throw new insufficient_fundsException();
                    }
                    else {
                        amount[i] -= withdraw;
                        System.out.println("Withdraw Successful!");
                    }
                }
                catch(invalid_AmmoutException exception){
                    System.out.println("Invalid Amount");

                }
                catch(insufficient_fundsException exception){
                    System.out.println("insufficient Funds ");
                }
                break;
            }
        }
        if (flag){
            System.out.println("Account not Found");
        }
    }
    public static void main(String[] args) {
        int n, flag = 1, ch;
        int[] accNumber = new int[25];
        int[] amount = new int[25];
        String[] Names = new String[25];
        Scanner scan = new Scanner(System.in);
        Custom_Exception e = new Custom_Exception();
        System.out.print("Enter No. of Customers: ");
        n = scan.nextInt();
        e.accounts(n, Names, accNumber, amount);
        System.out.println("Banking System\n1.Display All Accounts\n2.Search Account\n3.Deposit Amount\n4.Withdraw Amount\n5.Exit");
        while(flag ==1){
            System.out.println("Enter Choice: ");
            ch = scan.nextInt();
            switch(ch){
                case 1:
                    e.display(n, Names, accNumber, amount);
                    break;
                case 2:
                    e.search(n,Names,accNumber,amount);
                    break;
                case 3:
                    e.deposit(n,accNumber, amount);
                    break;
                case 4:
                    e.withdraw(n, accNumber, amount);
                    break;
                case 5:
                    System.out.println("Exiting");
                    flag = 0;
                    break;
                default:
                    System.out.println("Invalid Choice");
                    break;
            }
        }
        scan.close();
    }
}