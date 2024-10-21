

import java.io.*;

class Filecopy{
    public static void main(String[] args){
        FileInputStream f1 = null;
        FileOutputStream f2= null;
        try {
            f1 = new FileInputStream("test.txt");
            f2 = new FileOutputStream("cp.txt");
            int c;
            do {
                c=f1.read();
                if (c != -1){
                    f2.write((char) c);
                    System.out.print((char) c);
                }
            } while (c != -1);
        } catch (FileNotFoundException e){
            System.out.println("file not found");
            return;

        }catch (IOException e){
            System.out.println("error reading or writing file : "+ e.getMessage ());
        }finally{
            try{
                if (f1 !=null)
                    f1.close();
                if (f2 != null)
                    f2.close();

            }catch (IOException e ){
                System.out.println("error closing file : "+ e.getMessage());
            }
        }
    }
}