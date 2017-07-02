using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Egg {

    GameObject egg = null;
    int id = -1;
    int ownerID = -1;
    int x = -1;
    int y = -1;


    public GameObject GetEgg()
    {
        return (egg);
    }

    public void SetEgg(GameObject _egg)
    {
        egg = _egg;
    }

    public void SetX(int _x)
    {
        x = _x;
    }

    public void SetY(int _y)
    {
        y = _y;
    }

    public int GetX()
    {
        return (x);
    }

    public int GetY()
    {
        return (y);
    }

    public int GetId()
    {
        return (id);
    }

    public int GetOwnerId()
    {
        return (ownerID);
    }

    public Egg(int _id, int oid, int _x = -1, int _y = -1)
    {
        id = _id;
        ownerID = oid;
        x = _x;
        y = _y;
        GameObject tmp = null;
            if (field.egg != null && x > -1 && y > -1 && (tmp = field.GetTile(x, y)) != null)
        {
            egg = GameObject.Instantiate(field.egg);
            egg.transform.position = new Vector3(
                Random.Range(tmp.transform.position.x - tmp.transform.localScale.x / 2, tmp.transform.position.x + tmp.transform.localScale.x / 2),
                tmp.transform.position.y + tmp.transform.localScale.y / 2 + egg.transform.localScale.y / 2,
                Random.Range(tmp.transform.position.z - tmp.transform.localScale.z / 2, tmp.transform.position.z + tmp.transform.localScale.z / 2));
        }
    }

    public void ClearEgg()
    {
        if (egg != null)
        {
            GameObject.Destroy(egg);
            egg = null;
        }
        x = -1;
        y = -1;
        id = -1;
        ownerID = -1;
    }
	
}
