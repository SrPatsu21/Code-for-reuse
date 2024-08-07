package cards;

import players.Player;
import players.Slot;
import players.Table;

public class Fight
{
    private Player player;
    private Player enemy;
    private Slot[] p_slot = new Slot[Table.SLOTSN];
    private Slot[] e_slot = new Slot[Table.SLOTSN];

    public Fight()
    {

    }
    public Fight(Player player, Player enemy)
    {
        setPlayer(player);
        setEnemy(enemy);
    }
    //getter setter
    public Player getPlayer()
    {
        return player;
    }
    public void setPlayer(Player player)
    {
        this.player = player;
    }
    public Player getEnemy()
    {
        return enemy;
    }
    public void setEnemy(Player enemy)
    {
        this.enemy = enemy;
    }
    public Card getCard(Player player,int i)
    {
        return player.getTable().getSlotPos()[i].getCard();
    }
    public Slot[] getP_slot()
    {
        return p_slot;
    }
    public void setP_slot(Slot[] p_slot)
    {
        this.p_slot = p_slot;
    }
    public Slot[] getE_slot()
    {
        return e_slot;
    }
    public void setE_slot(Slot[] e_slot)
    {
        this.e_slot = e_slot;
    }

    //receiving damage
    public void cardReceiveDamage(Card card, int damage)
    {
        card.receiveDamage(damage);
    }
    public void arrangeSlots()
    {
        int p_cont = 0, e_cont = 0;
        for (int i = 0; i < Table.SLOTSN; i++)
        {
            this.p_slot[i]= new Slot(0,0,0,0);
            this.e_slot[i]= new Slot(0,0,0,0);

            if (getCard(getPlayer(), i) != null)
            {
                this.p_slot[p_cont].setCard(getCard(getPlayer(), i));
                p_cont++;
            }
            if (getCard(getEnemy(), i) != null)
            {
                this.e_slot[e_cont].setCard(getCard(getEnemy(), i));
                e_cont++;
            }
        }

    }
    //combat
    public void fight()
    {
        arrangeSlots();
        for (int i = 0; i < Table.SLOTSN; i++)
        {
            int player_d = 0;
            int enemy_d = 0;
            //set damage
            if (getP_slot()[i] != null)
            {
                if (getP_slot()[i].getCard() != null)
                {
                    player_d = getP_slot()[i].getCard().getActualDamage();
                }
            }

            if (getE_slot()[i] != null)
            {
                if (getE_slot()[i].getCard() != null)
                {
                    enemy_d = getE_slot()[i].getCard().getActualDamage();
                }
            }
            //receiving
            //player
            if (getP_slot()[i].getCard() != null)
            {
                cardReceiveDamage(getP_slot()[i].getCard(), enemy_d);
            }
            else
            {
                getPlayer().getPlayerStatus().receiveDamage(enemy_d);
            }
            //enemy
            if (getE_slot()[i].getCard()!= null)
            {
                cardReceiveDamage(getE_slot()[i].getCard(), player_d);
            }
            else
            {
                getEnemy().getPlayerStatus().receiveDamage(player_d);
            }
        }
        getPlayer().getTable().removeDeadCards();
        getEnemy().getTable().removeDeadCards();
    }
}
