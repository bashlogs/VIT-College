import java.util.ArrayList;
import java.util.List;

public class paging {
  public static void main(String[] args) {
    List<Integer> items = new ArrayList<>();
      for (int i = 1; i <= 300; i++) {
        items.add(i);
      }

    int pageSize = 10;
    int pageNumber = 10;

    int startIndex = (pageNumber - 1) * pageSize;
    int endIndex = startIndex + pageSize;
    List<Integer> page = items.subList(startIndex, endIndex);

    System.out.println("Page " + pageNumber + ": " + page);
  }
}
