class Dog{
  String breed;
  String size;
  int age;
  String colour;

  public String getInfo(){
    return ("Breed is: " +breed+", Size is:"+size+", Age is:"+age+", color is:"+colour);
  }
}

public class Execute{
  public static void main(String[]args){
    Dog maltese = new Dog();
    Dog NeapolitanMastiff = new Dog();
    Dog ChowChow = new Dog();
    Dog Corgi = new Dog();
    maltese.breed="Maltese";
    maltese.size="Small";
    maltese.age=2;
    maltese.colour="white";

    NeapolitanMastiff.breed="Neapolitan Mastiff";
    NeapolitanMastiff.size="Medium";
    NeapolitanMastiff.age=3;
    NeapolitanMastiff.colour="yellow";

    ChowChow.breed="Chow Chow";
    ChowChow.size="Small";
    ChowChow.age=1;
    ChowChow.colour="black";

    Corgi.breed="Corgi";
    Corgi.size="Small";
    Corgi.age=2;
    Corgi.colour="white";

    System.out.println(maltese.getInfo()+'\n'+NeapolitanMastiff.getInfo()+'\n'+ChowChow.getInfo()+'\n'+Corgi.getInfo());

  }
}
