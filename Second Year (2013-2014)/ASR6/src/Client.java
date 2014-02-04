import java.io.IOException;
import java.net.InetAddress;
import java.net.Socket;
import java.net.UnknownHostException;


public class Client {
    
    public static void main(String[] zero) {
        
        Socket socket;
        try {
             socket = new Socket(InetAddress.getLocalHost(),80); 
             System.out.println ("connexion au serveur réussie !");
             socket.close();
        }
        catch (UnknownHostException e) {   
            e.printStackTrace();
        }
        catch (IOException e) {    
            e.printStackTrace();
        }
    }
}