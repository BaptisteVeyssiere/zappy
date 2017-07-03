using System;
using System.Collections;
using System.Collections.Generic;
using System.Net;
using System.Net.Sockets;
using UnityEngine;
using UnityEngine.UI;

public class ConnectToServer : MonoBehaviour {

    private delegate void fptr(string[] cmd);
    private Dictionary<string, fptr> cmd_ptr = new Dictionary<string, fptr>();
    private const int BUFFLEN = 4096;
    private const int xSize = 5;
    private const int zSize = 5;
    private Socket clientSock = null;
    private byte[] buff = new byte[BUFFLEN];
    private byte[] over = null;
    private bool connected = false;
    private bool firstConnect = false;
    private List<string> cmd_client = new List<string>();

    [SerializeField]
    private GameObject cubRef;

    [SerializeField]
    private GameObject playerRef;

    [SerializeField]
    private GameObject eggRef;
    [SerializeField]
    private GameObject food;
    [SerializeField]
    private GameObject linemate;
    [SerializeField]
    private GameObject deraumere;
    [SerializeField]
    private GameObject sibur;
    [SerializeField]
    private GameObject mendiane;
    [SerializeField]
    private GameObject phiras;
    [SerializeField]
    private GameObject thystame;

    [SerializeField]
    private InputField ip;

    [SerializeField]
    private Button ConnectButton;

    [SerializeField]
    private Button QuitButton;

    [SerializeField]
    private GameObject canvas;


    void Quit()
    {
        disconnect();
        ClearGame();
        Application.Quit();
    }

    void Start () {
        Application.runInBackground = true;
        cmd_ptr["msz"] = cmd_msz;
        cmd_ptr["bct"] = cmd_bct;
        cmd_ptr["tna"] = cmd_tna;
        cmd_ptr["pnw"] = cmd_pnw;
        cmd_ptr["pic"] = cmd_pic;
        cmd_ptr["pie"] = cmd_pie;
        cmd_ptr["enw"] = cmd_enw;
        cmd_ptr["eht"] = cmd_eht;
        cmd_ptr["ebo"] = cmd_ebo;
        cmd_ptr["sgt"] = cmd_sgt;
        cmd_ptr["seg"] = cmd_seg;

        cmd_client.Add("ppo");
        cmd_client.Add("plv");
        cmd_client.Add("pin");
        cmd_client.Add("pex");
        cmd_client.Add("pbc");
        cmd_client.Add("pfk");
        cmd_client.Add("pdr");
        cmd_client.Add("pgt");
        cmd_client.Add("pdi");
        for (int i = 0; i < BUFFLEN; i++)
            buff[i] = 0;
        ConnectButton.onClick.AddListener(() => { Connect(); });
        QuitButton.onClick.AddListener(() => { Quit(); });
        field.egg = eggRef;
        field.food = food;
        field.linemate = linemate;
        field.deraumere = deraumere;
        field.sibur = sibur;
        field.mendiane = mendiane;
        field.phiras = phiras;
        field.thystane = thystame;
    }

    private void cmd_seg(string[] cmd)
    {
        //TODO
    }

    private void cmd_sgt(string[] cmd)
    {
        if (cmd.Length == 2)
        {
            try
            {
                field.freq = int.Parse(cmd[1]);
            }
            catch (Exception e)
            {
                Debug.LogError(e.Message);
                Console.Write(e.Message + "\n");
                print(e.Message + "\n");
            }
        }
        else
        {
            Debug.LogError("command " + cmd[0] + " contains " + cmd.Length.ToString() + " arguments");
            Console.Write("command " + cmd[0] + " contains " + cmd.Length.ToString() + " arguments\n");
            print("command " + cmd[0] + " contains " + cmd.Length.ToString() + " arguments\n");
        }
    }

    private void cmd_ebo(string[] cmd)
    {
        if (cmd.Length == 2)
        {
            int id = int.Parse(cmd[1]);
            try
            {
                for (int y = 0; y < field.height; y++)
                {
                    for (int x = 0; x < field.width; x++)
                    {
                        int isHere = -1;
                        for (int i = 0; i < field.items[y, x].eggs.Count; i++)
                        {
                            if (field.items[y, x].eggs[i].GetId() == id)
                            {
                                isHere = i;
                                break;
                            }
                        }
                        if (isHere != -1)
                        {
                            field.items[y, x].eggs[isHere].ClearEgg();
                            field.items[y, x].eggs.RemoveAt(isHere);
                            return;
                        }
                    }
                }
            }
            catch (Exception e)
            {
                Debug.LogError("command " + cmd[0] + " contains " + cmd.Length.ToString() + " arguments");
                Console.Write("command " + cmd[0] + " contains " + cmd.Length.ToString() + " arguments\n");
                print("command " + cmd[0] + " contains " + cmd.Length.ToString() + " arguments\n");
            }
        }
    }

    private void cmd_eht(string[] cmd)
    {
        //TODO
    }

    private void cmd_enw(string[] cmd)
    {
        if (cmd.Length == 5)
        {
            try
            {
                int eid = int.Parse(cmd[1]);
                int id = int.Parse(cmd[2]);
                int x = int.Parse(cmd[3]);
                int y = int.Parse(cmd[4]);
                Inventory items = null;
                if ((items = field.GetItem(x, y)) != null)
                {
                    Egg egg = new Egg(eid, id, x, y);
                    items.eggs.Add(egg);
                }
            }
            catch (Exception e)
            {
                Debug.LogError(e.Message);
                Console.Write(e.Message + "\n");
                print(e.Message + "\n");
            }
        }
        else
        {
            Debug.LogError("command " + cmd[0] + " contains " + cmd.Length.ToString() + " arguments");
            Console.Write("command " + cmd[0] + " contains " + cmd.Length.ToString() + " arguments\n");
            print("command " + cmd[0] + " contains " + cmd.Length.ToString() + " arguments\n");
        }
    }

    private void cmd_pie(string[] cmd)
    {
        //TODO
    }

    private void cmd_pic(string[] cmd)
    {
        if (cmd.Length >= 5)
        {
            try
            {
                int x = int.Parse(cmd[1]);
                int y = int.Parse(cmd[2]);
                int lv = int.Parse(cmd[3]);
                for (int i = 4; i < cmd.Length; i++)
                {
                    try
                    {
                        int id = int.Parse(cmd[i]);
                        for (int n = 0; n < field.players.Count; n++)
                        {
                            if (field.players[n].GetId() == id)
                            {
                                Behaviour halo = field.players[n].player.GetComponent("Halo") as Behaviour;
                                if (halo != null)
                                {
                                    halo.enabled = true;
                                }
                                break;
                            }
                        }
                    }
                    catch (Exception e)
                    {
                        Debug.LogError(e.Message);
                    }
                }
            }
            catch (Exception e)
            {
                Debug.LogError(e.Message);
            }
        }
    }

    private void cmd_pnw(string[] cmd)
    {
        if (cmd.Length == 7)
        {
            try
            {
                field.players.Add(new Player(
                    int.Parse(cmd[1]),
                    int.Parse(cmd[2]),
                    int.Parse(cmd[3]),
                    int.Parse(cmd[4]),
                    int.Parse(cmd[5]),
                    cmd[6],
                    playerRef));
            }
            catch (Exception e)
            {
                Debug.LogError(e.Message);
                Console.Write(e.Message + "\n");
                print(e.Message + "\n");
            }
        }
        else
        {
            Debug.LogError("command " + cmd[0] + " contains " + cmd.Length.ToString() + " arguments");
            Console.Write("command " + cmd[0] + " contains " + cmd.Length.ToString() + " arguments\n");
            print("command " + cmd[0] + " contains " + cmd.Length.ToString() + " arguments\n");
        }
    }

    private void cmd_tna(string[] cmd)
    {
        if (cmd.Length == 2)
        {
            if (!field.teams.Contains(cmd[1]))
            {
                field.teams.Add(cmd[1]);
            }
        }
        else
        {
            Debug.LogError("command " + cmd[0] + " contains " + cmd.Length.ToString() + " arguments");
            Console.Write("command " + cmd[0] + " contains " + cmd.Length.ToString() + " arguments\n");
            print("command " + cmd[0] + " contains " + cmd.Length.ToString() + " arguments\n");
        }
    }

    private void cmd_bct(string[] cmd)
    {
        if (cmd.Length == 10)
        {
            Inventory tmp = null;
            
            try
            {
                int x = int.Parse(cmd[1]);
                int y = int.Parse(cmd[2]);
                if ((tmp = field.GetItem(x, y)) == null)
                {
                    tmp = new Inventory();
                }
                tmp.SetFood(int.Parse(cmd[3]));
                tmp.SetLinemate(int.Parse(cmd[4]));
                tmp.SetDeraumere(int.Parse(cmd[5]));
                tmp.SetSibur(int.Parse(cmd[6]));
                tmp.SetMendiane(int.Parse(cmd[7]));
                tmp.SetPhiras(int.Parse(cmd[8]));
                tmp.SetThystame(int.Parse(cmd[9]));
                GameObject tile = null;
                if ((tile = field.GetTile(x, y)) != null)
                {
                    if (tmp.GetFood() > 0 && tmp.foodObj == null)
                    {
                        UnityEngine.Random.InitState(DateTime.Now.Millisecond);
                        tmp.foodObj = GameObject.Instantiate(field.food);
                        tmp.foodObj.transform.position = new Vector3(
                            UnityEngine.Random.Range((tile.transform.position.x - tile.transform.localScale.x / 2) + tmp.foodObj.transform.localScale.x / 2, (tile.transform.position.x + tile.transform.localScale.x / 2) - tmp.foodObj.transform.localScale.x / 2),
                            tile.transform.position.y + tile.transform.localScale.y / 2 + tmp.foodObj.transform.localScale.y / 2,
                            UnityEngine.Random.Range((tile.transform.position.z - tile.transform.localScale.z / 2) + tmp.foodObj.transform.localScale.z / 2, (tile.transform.position.z + tile.transform.localScale.z / 2) - tmp.foodObj.transform.localScale.z / 2));
                    }
                    else if (tmp.GetFood() <= 0 && tmp.foodObj != null)
                    {
                        Destroy(tmp.foodObj);
                        tmp.foodObj = null;
                    }
                    if (tmp.GetLinemate() > 0 && tmp.linemateObj == null)
                    {
                        UnityEngine.Random.InitState(DateTime.Now.Millisecond * 2);
                        tmp.linemateObj = GameObject.Instantiate(field.linemate);
                        tmp.linemateObj.transform.position = new Vector3(
                            UnityEngine.Random.Range((tile.transform.position.x - tile.transform.localScale.x / 2) + tmp.linemateObj.transform.localScale.x / 2, (tile.transform.position.x + tile.transform.localScale.x / 2) - tmp.linemateObj.transform.localScale.x / 2),
                            tile.transform.position.y + tile.transform.localScale.y / 2 + tmp.linemateObj.transform.localScale.y / 2,
                            UnityEngine.Random.Range((tile.transform.position.z - tile.transform.localScale.z / 2) + tmp.linemateObj.transform.localScale.z / 2, (tile.transform.position.z + tile.transform.localScale.z / 2) - tmp.linemateObj.transform.localScale.z / 2));
                    }
                    else if (tmp.GetLinemate() <= 0 && tmp.linemateObj != null)
                    {
                        Destroy(tmp.linemateObj);
                        tmp.linemateObj = null;
                    }
                    if (tmp.GetDeraumere() > 0 && tmp.deraumerObj == null)
                    {
                        UnityEngine.Random.InitState(DateTime.Now.Millisecond * 3);
                        tmp.deraumerObj = GameObject.Instantiate(field.deraumere);
                        tmp.deraumerObj.transform.position = new Vector3(
                            UnityEngine.Random.Range((tile.transform.position.x - tile.transform.localScale.x / 2) + tmp.deraumerObj.transform.localScale.x / 2, (tile.transform.position.x + tile.transform.localScale.x / 2) - tmp.deraumerObj.transform.localScale.x / 2),
                            tile.transform.position.y + tile.transform.localScale.y / 2 + tmp.deraumerObj.transform.localScale.y / 2,
                            UnityEngine.Random.Range((tile.transform.position.z - tile.transform.localScale.z / 2) + tmp.deraumerObj.transform.localScale.z / 2, (tile.transform.position.z + tile.transform.localScale.z / 2) - tmp.deraumerObj.transform.localScale.z / 2));
                    }
                    else if (tmp.GetDeraumere() <= 0 && tmp.deraumerObj != null)
                    {
                        Destroy(tmp.deraumerObj);
                        tmp.deraumerObj = null;
                    }
                    if (tmp.GetSibur() > 0 && tmp.siburObj == null)
                    {
                        UnityEngine.Random.InitState(DateTime.Now.Millisecond * 4);
                        tmp.siburObj = GameObject.Instantiate(field.sibur);
                        tmp.siburObj.transform.position = new Vector3(
                            UnityEngine.Random.Range((tile.transform.position.x - tile.transform.localScale.x / 2) + tmp.siburObj.transform.localScale.x / 2, (tile.transform.position.x + tile.transform.localScale.x / 2) - tmp.siburObj.transform.localScale.x / 2),
                            tile.transform.position.y + tile.transform.localScale.y / 2 + tmp.siburObj.transform.localScale.y / 2,
                            UnityEngine.Random.Range((tile.transform.position.z - tile.transform.localScale.z / 2) + tmp.siburObj.transform.localScale.z / 2, (tile.transform.position.z + tile.transform.localScale.z / 2)) - tmp.siburObj.transform.localScale.z / 2);
                    }
                    else if (tmp.GetSibur() <= 0 && tmp.siburObj != null)
                    {
                        Destroy(tmp.siburObj);
                        tmp.siburObj = null;
                    }
                    if (tmp.GetMendiane() > 0 && tmp.mendianeObj == null)
                    {
                        UnityEngine.Random.InitState(DateTime.Now.Millisecond * 5);
                        tmp.mendianeObj = GameObject.Instantiate(field.mendiane);
                        tmp.mendianeObj.transform.position = new Vector3(
                            UnityEngine.Random.Range((tile.transform.position.x - tile.transform.localScale.x / 2) + tmp.mendianeObj.transform.localScale.x / 2, (tile.transform.position.x + tile.transform.localScale.x / 2) - tmp.mendianeObj.transform.localScale.x / 2),
                            tile.transform.position.y + tile.transform.localScale.y / 2 + tmp.mendianeObj.transform.localScale.y / 2,
                            UnityEngine.Random.Range((tile.transform.position.z - tile.transform.localScale.z / 2) + tmp.mendianeObj.transform.localScale.z / 2, (tile.transform.position.z + tile.transform.localScale.z / 2) - tmp.mendianeObj.transform.localScale.z / 2));
                    }
                    else if (tmp.GetMendiane() <= 0 && tmp.mendianeObj != null)
                    {
                        Destroy(tmp.mendianeObj);
                        tmp.mendianeObj = null;
                    }
                    if (tmp.GetPhiras() > 0 && tmp.phirasObj == null)
                    {
                        UnityEngine.Random.InitState(DateTime.Now.Millisecond * 6);
                        tmp.phirasObj = GameObject.Instantiate(field.phiras);
                        tmp.phirasObj.transform.position = new Vector3(
                            UnityEngine.Random.Range((tile.transform.position.x - tile.transform.localScale.x / 2) + tmp.phirasObj.transform.localScale.x / 2, (tile.transform.position.x + tile.transform.localScale.x / 2) - tmp.phirasObj.transform.localScale.x / 2),
                            tile.transform.position.y + tile.transform.localScale.y / 2 + tmp.phirasObj.transform.localScale.y / 2,
                            UnityEngine.Random.Range((tile.transform.position.z - tile.transform.localScale.z / 2) + tmp.phirasObj.transform.localScale.z / 2, (tile.transform.position.z + tile.transform.localScale.z / 2) - tmp.phirasObj.transform.localScale.z / 2));
                    }
                    else if (tmp.GetPhiras() <= 0 && tmp.phirasObj != null)
                    {
                        Destroy(tmp.phirasObj);
                        tmp.phirasObj = null;
                    }
                    if (tmp.GetThystame() > 0 && tmp.thystameObj == null)
                    {
                        UnityEngine.Random.InitState(DateTime.Now.Millisecond * 7);
                        tmp.thystameObj = GameObject.Instantiate(field.thystane);
                        tmp.thystameObj.transform.position = new Vector3(
                            UnityEngine.Random.Range((tile.transform.position.x - tile.transform.localScale.x / 2) + tmp.thystameObj.transform.localScale.x / 2, (tile.transform.position.x + tile.transform.localScale.x / 2) - tmp.thystameObj.transform.localScale.x / 2),
                            tile.transform.position.y + tile.transform.localScale.y / 2 + tmp.thystameObj.transform.localScale.y / 2,
                            UnityEngine.Random.Range((tile.transform.position.z - tile.transform.localScale.z / 2) + tmp.thystameObj.transform.localScale.z / 2, (tile.transform.position.z + tile.transform.localScale.z / 2) - tmp.thystameObj.transform.localScale.z / 2));
                    }
                    else if (tmp.GetThystame() <= 0 && tmp.thystameObj != null)
                    {
                        Destroy(tmp.thystameObj);
                        tmp.thystameObj = null;
                    }
                }
                field.SetItem(x, y, tmp);
            }
            catch (Exception e)
            {
                Debug.LogError(e.Message);
                Console.Write(e.Message + "\n");
            }

        }
        else
        {
            Debug.LogError("command " + cmd[0] + " contains " + cmd.Length.ToString() + " arguments");
            Console.Write("command " + cmd[0] + " contains " + cmd.Length.ToString() + " arguments\n");
            print("command " + cmd[0] + " contains " + cmd.Length.ToString() + " arguments\n");
        }
    }

    private void cmd_msz(string[] cmd)
    {
        if (cmd.Length == 3)
        {
            try
            {
                int x = int.Parse(cmd[1]);
                int y = int.Parse(cmd[2]);
                setMap(x, y);
            }
            catch (Exception e)
            {
                Debug.LogError(e.Message);
                Console.Write(e.Message + "\n");
            }
        }
        else
        {
            Debug.LogError("command " + cmd[0] + " contains " + cmd.Length.ToString() + " arguments");
            Console.Write("command " + cmd[0] + " contains " + cmd.Length.ToString() + " arguments\n");
            print("command " + cmd[0] + " contains " + cmd.Length.ToString() + " arguments\n");
        }
    }
    

    void FixedUpdate()
    {
        try
        {
            if (clientSock != null && clientSock.Available > 0)
            {
                ReceiveData();
            }
            if (connected && field.commands.Count > 0)
            {
                int len = -1;
                bool end = false;
                while (!end && ++len < field.commands.Count)
                {
                    string[] splitCmd = field.commands[len].Split(' ');
                    if (splitCmd.Length > 1)
                    {
                        if (cmd_client.Contains(splitCmd[0]))
                        {
                            end = true;
                        }
                        else if (cmd_ptr.ContainsKey(splitCmd[0]))
                        {
                            cmd_ptr[splitCmd[0]](splitCmd);
                        }
                    }
                }
                for (int i = 0; i < len; ++i)
                {
                    field.commands.RemoveAt(0);
                }
            }
            else
            {
                Console.Write("disconnected or no command\n");
            }
        }
        catch (Exception e)
        {
            Console.Write("Update exception " + e.Message + "\n");
        }
    }

    private void LateUpdate()
    {
        if (firstConnect)
        {
            try
            {
                canvas.SetActive(false);
                Cursor.lockState = CursorLockMode.Locked;
                Cursor.visible = false;
                field.camState = 0;
                firstConnect = false;
            }
            catch (Exception e)
            {
                Debug.LogError(e.Message);
            }
        }
    }

    void setMap(int maxX, int maxY)
    {
        bool failed = false;
        GameObject[,] map = new GameObject[maxY, maxX];
        Inventory[,] items = new Inventory[maxY, maxX];
        for (int y = 0; y < maxY && failed == false; y++)
        {
            for (int x = 0; x < maxX && failed == false; x++)
            {
                try
                {
                    map[y, x] = Instantiate(cubRef, Vector3.zero + new Vector3(-x * cubRef.transform.localScale.x, 0, y * cubRef.transform.localScale.z), Quaternion.identity);
                    map[y, x].SetActive(true);
                    if (((x + y) % 2) == 0)
                        map[y, x].GetComponent<Renderer>().material.color = Color.black;
                    else
                        map[y, x].GetComponent<Renderer>().material.color = Color.grey;
                }
                catch (Exception e)
                {
                    failed = true;
                    Debug.LogError(e.Message);
                    Console.Write(e.Message + "\n");
                    print(e.Message + "\n");

                }
            }
        }
        if (!failed)
            field.SetMap(map, items, maxX, maxY);
    }

    void    Connect()
    {
        ClearGame();
        disconnect();
        string target = ip.text;
        if (target.Length == 0)
            target = "127.0.0.1";
        try
        {
            clientSock = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            clientSock.Connect(new IPEndPoint(IPAddress.Parse(target), 50000));
            clientSock.ReceiveBufferSize = BUFFLEN;
            clientSock.ReceiveTimeout = 100;
        }
        catch (SocketException e)
        {
            Debug.LogError(e.Message);
        }
    }

    void    ReceiveData()
    {
        try
        {
            int len = clientSock.Receive(buff);
            if (len > 0)
            {
                byte[] tmp = null;
                if (over != null)
                {
                    tmp = new byte[len + over.Length];
                    int j = -1;
                    for (int i = 0; i < over.Length; i++)
                        tmp[++j] = over[i];
                    for (int i = 0; i < len; i++)
                        tmp[++j] = buff[i];
                    over = null;
                }
                else
                {
                    tmp = new byte[len];
                    for (int i = 0; i < len; i++)
                        tmp[i] = buff[i];
                }

                if (!connected)
                {
                    if (string.Compare(System.Text.Encoding.ASCII.GetString(tmp), 0, "BIENVENUE\n", 0, 10) != 0)
                    {
                        disconnect();
                        return;
                    }
                    clientSock.Send(System.Text.Encoding.ASCII.GetBytes("GRAPHIC\n"));
                    connected = true;
                    firstConnect = true;
                    byte[] temp = new byte[tmp.Length - 10];
                    Buffer.BlockCopy(tmp, 9, temp, 0, tmp.Length - 10);
                    tmp = temp;
                }
                string[] list = System.Text.Encoding.ASCII.GetString(tmp).Split('\n');
                if (list != null)
                {
                    for (int i = 0; i < list.Length; i++)
                    {
                        if (list[i].Length > 0 && i + 1 < list.Length)
                        {
                            field.commands.Add(list[i]);
                        }
                        if (i + 1 >= list.Length)
                        {
                            if (list[i].Length > 0)
                            {
                                over = System.Text.Encoding.ASCII.GetBytes(list[i]);
                            }
                            else
                            {
                                over = null;
                            }
                        }
                    }
                }
                for (int i = 0; i < BUFFLEN; i++)
                    buff[i] = 0;
            }
        }
        catch (Exception e)
        {
            Console.Write("Receive exception " + e.Message + "\n");
            throw new Exception();
        }
    }

    void    disconnect()
    {
        if (clientSock != null)
            clientSock.Disconnect(true);
        for (int i = 0; i < BUFFLEN; i++)
            buff[i] = 0;
        over = null;
        connected = false;
        firstConnect = false;
        clientSock = null;
    }

    void ClearGame()
    {
        over = null;
        field.commands.Clear();
        field.commands = new List<string>();
        field.teams.Clear();
        field.teams = new List<string>();
        for (int i = 0; i < field.players.Count; i++)
        {
            field.players[i].ClearPlayer();
        }
        field.players.Clear();
        field.players = new List<Player>();
        field.ClearMap();
    }
}
