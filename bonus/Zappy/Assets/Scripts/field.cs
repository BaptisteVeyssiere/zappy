using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public static class field
{

    public static Camera Cam = null;

    public static int camState = 0;

    public static int playerId = -1;

    public static Player playerFollow = null;

    public static GameObject egg;
    public static GameObject food;
    public static GameObject linemate;
    public static GameObject deraumere;
    public static GameObject sibur;
    public static GameObject mendiane;
    public static GameObject phiras;
    public static GameObject thystane;


    public static List<Player> players = new List<Player>();
    public static List<string> teams = new List<string>();

    public static List<string> commands = new List<string>();

    public static float minX = 0;
    public static float maxX = 0;
    public static float minZ = 0;
    public static float maxZ = 0;

    public static float blockX = 0;
    public static float blockZ = 0;

    public static int width = 0;
    public static int height = 0;

    public static int freq = 7;
    

    private static GameObject[,] map = null;
    public static Inventory[,] items = null;

    public static void setPlayerFollow(int id)
    {
        Player tmp = null;
        for (int i = 0; i < players.Count; i++)
        {
            if (players[i].GetId() == id)
            {
                tmp = players[i];
                break;
            }
        }
        if (tmp != null)
        {
            camState = 1;
            playerFollow = tmp;
            playerId = id;
        }
    }

    public static void clearPlayerFollow()
    {
        camState = 0;
        playerId = -1;
        playerFollow = null;
    }

    public static GameObject GetCamOnField()
    {
        if (width > 0 && height > 0)
        {
            int x = width / 2;
            int y = height / 2;
            return (map[y, x]);
        }
        return (null);
    }

    public static void killPlayer(int id)
    {
        if (playerId == id)
        {
            camState = 0;
            playerId = -1;
            playerFollow = null;
        }
        Player tmp = null;
        for (int i = 0; i < players.Count; i++)
        {
            if (players[i].GetId() == id)
            {
                tmp = players[i];
                break;
            }
        }
        if (tmp != null)
        {
            players.Remove(tmp);
            tmp.killPlayer();
            GameObject.Destroy(tmp.player);
        }
    }

    public static void SetMap(GameObject[,] _map, Inventory[,] _items, int _width, int _height)
    {
        
        width = _width;
        height = _height;
        map = _map;
        items = _items;

        blockX = map[0, 0].transform.localScale.x;
        blockZ = map[0, 0].transform.localScale.z;

        minX = map[height - 1, width - 1].transform.position.x - map[height - 1, width - 1].transform.localScale.x / 2;
        maxX = map[0, 0].transform.position.x + map[0, 0].transform.localScale.x / 2;
        minZ = map[0, 0].transform.position.z - map[0, 0].transform.localScale.z / 2;
        maxZ = map[height - 1, width - 1].transform.position.z + map[height - 1, width - 1].transform.localScale.z / 2;

    }

    public static void SetItem(int x, int y, Inventory item)
    {
        if (x < width && x >= 0 && y < height && y >= 0)
        {
            items[y, x] = item;
        }
    }

    public static Inventory GetItem(int x, int y)
    {
        if (x < width && x >= 0 && y < height && y >= 0)
        {
            return (items[y, x]);
        }
        return (null);
    }

    public static GameObject GetTile(int x, int y)
    {
        if (x < width && x >= 0 && y < height && y >= 0)
        {
            return (map[y, x]);
        }
        return (null);
    }

    public static void ClearMap()
    {
        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                GameObject.Destroy(map[y, x]);
                items[y, x].ClearInventory();
            }
        }
        items = null;
        map = null;
        minX = 0;
        maxX = 0;
        minZ = 0;
        maxZ = 0;
        width = 0;
        height = 0;
        blockX = 0;
        blockZ = 0;
        freq = 7;
        camState = 0;
        playerFollow = null;
    }

    public static void FollowPlayer(int id)
    {
        for (int i = 0; i < players.Count; i++)
        {
            if (players[i].GetId() == id)
            {
                playerFollow = players[i];
                return;
            }
        }
        playerFollow = null;
    }

}
