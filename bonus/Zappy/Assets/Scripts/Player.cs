using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Player {

    private Text text = null;
    public Canvas canvas = null;
    private bool alive = false;
    public GameObject player = null;
    public float randX = 0;
    public float randZ = 0;
    string team = null;
    int id = 0;
    int level = 0;
    int orientation = 0;
    Inventory items = null;
    int posX = 0;
    int posY = 0;


    public Inventory GetItems()
    {
        return (items);
    }

    public void SetItems(Inventory _items)
    {
        items = _items;
    }

    public int GetOrientation()
    {
        return (orientation);
    }

    public void SetOrientation(int o)
    {
        orientation = o;
    }

    public void SetLevel(int val)
    {
        level = val;
    }

    public int GetLevel()
    {
        return (level);
    }

    public int GetX()
    {
        return (posX);
    }

    public int GetY()
    {
        return (posY);
    }

    public void SetX(int val)
    {
        posX = val;
    }

    public void SetY(int val)
    {
        posY = val;
    }

    public string GetTeam()
    {
        return (team);
    }

    public int GetId()
    {
        return (id);
    }

    public void killPlayer()
    {
        alive = false;
    }

    public bool isAlive()
    {
        return (alive);
    }

    public void updateLevel()
    {
        if (text != null)
            text.text = team.ToString() + " " + level.ToString();
    }

    public Player(int _id, int x, int y, int o, int lv, string _team, GameObject copy)
    {
        GameObject tmp = null;
        if ((tmp = field.GetTile(x, y)) != null)
        {
            id = _id;
            posX = x;
            posY = y;
            orientation = o;
            level = lv;
            team = _team;
            player = GameObject.Instantiate(copy);
            randX = Random.Range(0 + player.transform.localScale.x / 2, field.blockX - player.transform.localScale.x / 2);
            randZ = Random.Range(0 + player.transform.localScale.z / 2, field.blockZ - player.transform.localScale.z / 2);
            player.transform.position = new Vector3(
                tmp.transform.position.x - tmp.transform.localScale.x / 2 + randX,
                tmp.transform.position.y + tmp.transform.localScale.y / 2 + player.transform.localScale.y,
                tmp.transform.position.z - tmp.transform.localScale.z / 2 + randZ);
            player.transform.rotation = Quaternion.Euler(0, (o - 1) * 90, 0);
            canvas = player.GetComponentInChildren<Canvas>();
            if (field.Cam != null)
                canvas.transform.LookAt(field.Cam.transform);
            text = canvas.GetComponentInChildren<Text>();
            if (text != null)
                text.text = team.ToString() + " " + level.ToString();
            Client client = player.GetComponent(typeof(Client)) as Client;
            client.SetPlayer(this);
            alive = true;
        }
    }

    public void ClearPlayer()
    {
        if (player != null)
        {
            GameObject.Destroy(player);
            player = null;
        }
        if (items != null)
        {
            items.ClearInventory();
            items = null;
        }
        alive = false;
        randX = 0;
        randZ = 0;
        team = null;
        id = 0;
        level = 0;
        orientation = 0;
        posX = 0;
        posY = 0;
        canvas = null;
        text = null;
    }

}
