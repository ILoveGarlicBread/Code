import java.util.Iterator;
import java.util.Vector;

enum OrderStatus {
  ORDERED, IN_KITCHEN, DELIVERING, DELIVERED, ARCHIVED, INACTIVE
};

public class MealOrderMgmt {
  private Vector<MealOrder> orders = new Vector<MealOrder>();

  public void addMealOrder(MealOrder mo) {
    if (mo != null)
      this.orders.add(mo);
  }

  public void updateMealOrder(int oID, OrderStatus newStatus) {
    Iterator<MealOrder> iterator = this.orders.iterator();
    MealOrder theOrder = null;

    while (iterator.hasNext()) {
      MealOrder currentOrder = iterator.next();
      if (currentOrder.getOrderID() == oID) {
        theOrder = currentOrder;
        break;
      }
    }

    if (theOrder != null)
      theOrder.setStatus(newStatus);
  }

  public int countNumberOf(OrderStatus aStatus) {
    Iterator<MealOrder> iterator = this.orders.iterator();
    int count = 0;

    while (iterator.hasNext()) {
      if (iterator.next().getStatus() == aStatus)
        count++;
    }

    return count;
  }

  public int getOrderCount() {
    return this.orders.size();
  }

  public static void main(String[] args) {
    MealOrderMgmt mgmt = new MealOrderMgmt();

    mgmt.addMealOrder(new MealOrder(1001));
    mgmt.addMealOrder(new MealOrder(1002));
    mgmt.addMealOrder(new MealOrder(1003));

    System.out.println("Total number of: " + String.valueOf(mgmt.getOrderCount()));
    System.out.println("Number of INACTIVE: " + String.valueOf(mgmt.countNumberOf(OrderStatus.INACTIVE)));
    System.out.println("Number of DELIVERED: " + String.valueOf(mgmt.countNumberOf(OrderStatus.DELIVERED)));

    mgmt.updateMealOrder(1003, OrderStatus.DELIVERED);

    System.out.println("Number of DELIVERED: " + String.valueOf(mgmt.countNumberOf(OrderStatus.DELIVERED)));

  }
}

class MealOrder {
  private int customerID;
  private OrderStatus status;
  private int orderID;

  MealOrder(int ID) {
    this.status = OrderStatus.INACTIVE;
    this.orderID = ID;
  }

  public void setStatus(OrderStatus newStatus) {
    this.status = newStatus;
  }

  public OrderStatus getStatus() {
    return this.status;
  }

  public int getOrderID() {
    return this.orderID;
  }

}
