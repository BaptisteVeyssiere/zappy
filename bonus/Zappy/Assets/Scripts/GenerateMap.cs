using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GenerateMap : MonoBehaviour {

    [SerializeField]
    private GameObject first;
    

	// Use this for initialization
	void Start () {
        setMap(10, 10);
    }

    void    setMap(int maxX, int maxY)
    {
        GameObject[,] map = new GameObject[maxY, maxX];
        Inventory[,] items = new Inventory[maxY, maxX];
        for (int y = 0; y < 10; y++)
        {
            for (int x = 0; x < 10; x++)
            {
                map[y, x] = Instantiate(first, first.transform.position + new Vector3(x * first.transform.localScale.x, 0, y * first.transform.localScale.z), Quaternion.identity);
                map[y, x].SetActive(true);
                if (((x + y) % 2) == 0)
                    map[y, x].GetComponent<Renderer>().material.color = Color.black;
                else
                    map[y, x].GetComponent<Renderer>().material.color = Color.grey;
            }
        }
        field.SetMap(map, items, maxX, maxY);
    }

}
