import java.util.Scanner;
import java.nio.file.Files;
import java.io.IOException;
import java.util.List;
import java.nio.file.Path;
import java.util.ArrayList;

public class main{
    class Trip{
        int id;
        String city;
        String date;
        int days;
        double price;
        String TypeOfVeh;

        Trip(int id, String city, String date, int days, double price, String TypeOfVeh){
            this.id = id;
            this.city = city;
            this.date = date;
            this.price = price;
            this.TypeOfVeh = TypeOfVeh;

        }
    }
    public static final String COMMA_DELIMITER = ";";
    public static void main(String[] args) throws IOException{

        List<String> lines = Files.readAllLines(Path.of("db.csv"));

        for (String line : lines){
            System.out.println(line);
        }

    }
}