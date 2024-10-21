    import java.io.*;
import java.util.Scanner;

class FileReader$Writer {
    public static void main(String[] args) {
        String s;
        Scanner sc = new Scanner(System.in);

        try {
            FileWriter fw = new FileWriter("test.txt");
            System.out.println("Enter lines of text (type 'stop' to end):");

            do {
                s = sc.nextLine();
                if (!s.equals("stop")) {
                    fw.write(s);
                    fw.write("\n");
                }
            } while (!s.equals("stop"));

            fw.close();

            try {
                FileReader fr = new FileReader("test.txt");
                BufferedReader br = new BufferedReader(fr);
                System.out.println("Content in the file is:");

                while ((s = br.readLine()) != null) {
                    System.out.println(s);
                }

                br.close();
                fr.close();
            } catch (FileNotFoundException fe) {
                System.out.println("File not found");
            }
        } catch (IOException e) {
            System.out.println("An error occurred: " + e.getMessage());
        } finally {
            sc.close();
        }
    }
}