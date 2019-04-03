import java.util.HashMap;
import java.util.TreeMap;
import java.util.*;

public class javaHashing{
  public static void main(String[] args){
    HashMap<String, Double> map = new HashMap<>();
    map.put("APPL", 147.0); //
    map.put("IBM", 118.0);
    map.put("X", 62.0);
    map.put("JPM", 105.0);
    System.out.println(map.get("APPL"));

    Iterator it = map.entrySet().iterator();
    while (it.hasNext()) {
        Map.Entry pair = (Map.Entry)it.next();
        System.out.println(pair.getKey() + " = " + pair.getValue());
    }
  }
}
