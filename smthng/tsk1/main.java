import java.util.ArrayList;
import java.util.Scanner;
import java.io.File;
import java.io.PrintWriter;

public class main {

    static class Student {
        String name;
        String surname;
        ArrayList<Integer> grades = new ArrayList<>();
    }

    static boolean scholarShip(Student student ){
        int sevens = 0;

        for (int grades : student.grades){
            if (grades < 7){
                return false;
            }
            if (grades == 7){
                sevens ++ ;
            }
        }
        return sevens <= 2;
    }

    static int countSevent(Student student){
        int sevens = 0;

        for (int grades : student.grades){
            if (grades == 7) {
                sevens ++;
            }
        }
        return sevens;
    }
    public static void main(String[] args) throws Exception {

        Scanner file = new Scanner(new File("students.txt"));
        ArrayList<Student> students = new ArrayList<>();
        
        while (file.hasNextLine()) {
            String line = file.nextLine();
            Scanner ss = new Scanner(line);

            if (!ss.hasNext()) {
                ss.close();
                continue;
            }

            Student student = new Student();

            student.name = ss.next();

            if (!ss.hasNext()) {
                ss.close();
                continue;
            }

            student.surname = ss.next();

            while (ss.hasNextInt()) {
                int grade = ss.nextInt();
                student.grades.add(grade);
            }

            students.add(student);
            ss.close();
        }

        file.close();

        for (Student student : students) {
            System.out.println(
                student.name + " " +
                student.surname + " " +
                student.grades
            );
        }

        PrintWriter output = new PrintWriter("scholarship.txt");

        for (Student student : students){
            if (scholarShip(student)){
                int sevens = countSevent(student);
                output.println(student.name + " " + student.surname + " " + sevens);
            }

        }
        output.close();

        System.out.println("Scholarships applied to: ");

        for (Student student : students){
            if (scholarShip(student)){
                int sevens = countSevent(student);
                System.out.println(student.name + " " + student.surname + " " + sevens + " approved!");
            }
        }
        }
    }
