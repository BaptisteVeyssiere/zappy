using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class BoardGame : MonoBehaviour {

    [SerializeField]
    private GameObject teamBoard;

    [SerializeField]
    private GameObject playerBoard;


    [SerializeField]
    private GameObject modele;

    private List<GameObject> teams = new List<GameObject>();
    private List<GameObject> players = new List<GameObject>();

    private string active = "All players";
    
    void Start () {
        GameObject all = Instantiate(modele);
        all.name = "All players";
        all.GetComponentInChildren<Text>().text = "All players";
        all.transform.SetParent(teamBoard.transform);
        Button button = all.GetComponent<Button>();
        button.onClick.AddListener(() => { displayAll(); });
        all.SetActive(true);
        teams.Add(all);
	}

    void displayAll()
    {
        try
        {
            for (int i = 0; i < players.Count; i++)
            {
                players[i].SetActive(true);
            }
            active = "All players";
        }
        catch (System.Exception e)
        {
            Debug.LogError("Message Exception Display All:");
            Debug.LogError(e.Message);
        }
    }

    private void LateUpdate()
    {
        try
        {
            for (int i = 1; i < teams.Count; i++)
            {
                if (!field.teams.Contains(teams[i].name))
                {
                    if (teams[i].activeSelf)
                        teams[i].SetActive(false);
                }
                else
                {
                    if (!teams[i].activeSelf)
                        teams[i].SetActive(true);
                }
            }
            for (int i = 0; i < field.teams.Count; i++)
            {
                bool exist = false;
                for (int j = 1; j < teams.Count && !exist; j++)
                {
                    if (field.teams[i].Equals(teams[j].name))
                        exist = true;
                }
                if (!exist)
                {
                    GameObject item = Instantiate(modele);
                    item.name = field.teams[i];
                    item.GetComponentInChildren<Text>().text = field.teams[i];
                    item.transform.SetParent(teamBoard.transform);
                    Button button = item.GetComponent<Button>();
                    button.onClick.AddListener(() => { displayPlayersFrom(item.name); });
                    item.SetActive(true);
                    teams.Add(item);
                }
            }
            for (int i = 0; i < players.Count; i++)
            {
                bool exist = false;
                for (int j = 0; j < field.players.Count && !exist; j++)
                {
                    if (players[i].name.Equals(field.players[j].GetTeam() + field.players[j].GetId().ToString()))
                        exist = true;
                }
                if (exist &&
                    ((players[i].name.Length > active.Length &&
                    string.Compare(players[i].name, 0, active, 0, active.Length) == 0) ||
                    active.Equals("All players")))
                {
                    if (!players[i].activeSelf)
                        players[i].SetActive(true);
                }
                else
                {
                    if (players[i].activeSelf)
                        players[i].SetActive(false);
                }
            }
            for (int i = 0; i < field.players.Count; i++)
            {
                bool exist = false;
                for (int j = 0; j < players.Count && !exist; j++)
                {
                    if (players[j].name.Equals(field.players[i].GetTeam() + field.players[i].GetId().ToString()))
                    {
                        exist = true;
                    }
                }
                if (!exist)
                {
                    GameObject item = Instantiate(modele);
                    item.name = field.players[i].GetTeam() + field.players[i].GetId().ToString();
                    item.GetComponentInChildren<Text>().text = field.players[i].GetTeam() + ": Player" + field.players[i].GetId().ToString();
                    item.transform.SetParent(playerBoard.transform);
                    Button button = item.GetComponent<Button>();
                    int id = field.players[i].GetId();
                    button.onClick.AddListener(() => { FollowPlayer(id); });
                    if (field.players[i].GetTeam().Equals(active) || active.Equals("All players"))
                    {
                        item.SetActive(true);
                    }
                    else
                    {
                        item.SetActive(false);
                    }
                    players.Add(item);
                }
            }
        }
        catch (System.Exception e)
        {
            Debug.LogError("Message Exception Loop:");
            Debug.LogError(e.Message);
        }
    }

    void FollowPlayer(int id)
    {
        field.setPlayerFollow(id);
    }

    void displayPlayersFrom(string team)
    {
        try
        {
            for (int i = 0; i < players.Count; i++)
            {
                if (players[i].name.Length > team.Length && string.Compare(players[i].name, 0, team, 0, team.Length) == 0)
                {
                    players[i].SetActive(true);
                }
            }
            active = team;
        }
        catch (System.Exception e)
        {
            Debug.LogError("Message Exception Display players from:");
            Debug.LogError(e.Message);
        }
    }

}
