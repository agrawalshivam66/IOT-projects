import java.net.*;  
public class DReceiver{  
  public static void main(String[] args) throws Exception {  
    DatagramSocket ds = new DatagramSocket(3000);  
    byte[] buf = new byte[1024];  
    DatagramPacket dp = new DatagramPacket(buf, 1024);  
    ds.receive(dp);
	int count = 0;  
    String str = new String(dp.getData(), 0, dp.getLength());  
    Scanner sc = new Scanner(new File("file.txt"));
    while(sc.hasNext()){
        String s = sc.next();
        if(str==s){
        	count++;
        }
    } 
    ds.close();  
  }  
} 