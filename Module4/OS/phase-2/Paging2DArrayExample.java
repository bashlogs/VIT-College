public class Paging2DArrayExample 
{    
  public static void main(String[] args) 
    {        
      char[][] items = new char[300][4];        
      int count = 1;        
      for (int i = 0; i < 300; i++) {            
        for (int j = 0; j < 4; j++) {                
          items[i][j] = count;                
          count++;            
        }        
      }
      int pageSize = 10; 
      int pageNumber = 1;
      int startRow = (pageNumber - 1) * pageSize;        
      int endRow = startRow + pageSize;
      System.out.println("Page " + pageNumber + ":");        
      for(int i=0;i<300;i++){
        System.out.println("Memory["+i+"] "+items[i]);
      }
    }
}
