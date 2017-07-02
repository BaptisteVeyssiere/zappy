using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Inventory
{
    public List<Egg> eggs = new List<Egg>();
    private int Food = 0;
    public GameObject foodObj = null;
    private int Linemate = 0;
    public GameObject linemateObj = null;
    private int Deraumere = 0;
    public GameObject deraumerObj = null;
    private int Sibur = 0;
    public GameObject siburObj = null;
    private int Mendiane = 0;
    public GameObject mendianeObj = null;
    private int Phiras = 0;
    public GameObject phirasObj = null;
    private int Thystame = 0;
    public GameObject thystameObj = null;

    public void SetFood(int val)
    {
        Food = val;
    }

    public int GetFood()
    {
        return (Food);
    }

    public void SetLinemate(int val)
    {
        Linemate = val;
    }

    public int GetLinemate()
    {
        return (Linemate);
    }

    public void SetDeraumere(int val)
    {
        Deraumere = val;
    }

    public int GetDeraumere()
    {
        return (Deraumere);
    }

    public void SetSibur(int val)
    {
        Sibur = val;
    }

    public int GetSibur()
    {
        return (Sibur);
    }

    public void SetMendiane(int val)
    {
        Mendiane = val;
    }

    public int GetMendiane()
    {
        return (Mendiane);
    }

    public void SetPhiras(int val)
    {
        Phiras = val;
    }

    public int GetPhiras()
    {
        return (Phiras);
    }

    public void SetThystame(int val)
    {
        Thystame = val;
    }

    public int GetThystame()
    {
        return (Thystame);
    }

    public Inventory()
    {
    }

    public void ClearInventory()
    {
        Food = 0;
        Linemate = 0;
        Deraumere = 0;
        Sibur = 0;
        Mendiane = 0;
        Phiras = 0;
        Thystame = 0;
        if (foodObj != null)
        {
            GameObject.Destroy(foodObj);
            foodObj = null;
        }
        if (linemateObj != null)
        {
            GameObject.Destroy(linemateObj);
            linemateObj = null;
        }
        if (deraumerObj != null)
        {
            GameObject.Destroy(deraumerObj);
            deraumerObj = null;
        }
        if (siburObj != null)
        {
            GameObject.Destroy(siburObj);
            siburObj = null;
        }
        if (mendianeObj != null)
        {
            GameObject.Destroy(mendianeObj);
            mendianeObj = null;
        }
        if (phirasObj != null)
        {
            GameObject.Destroy(phirasObj);
            phirasObj = null;
        }
        if (thystameObj != null)
        {
            GameObject.Destroy(thystameObj);
            thystameObj = null;
        }
        for (int i = 0; i < eggs.Count; i++)
        {
            eggs[i].ClearEgg();
        }
        eggs.Clear();
    }

}