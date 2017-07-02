using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Client : MonoBehaviour {

    private Player player = null;
    private delegate void fptr(string[] cmd);
    private Dictionary<string, fptr> cmd_ptr = new Dictionary<string, fptr>();

    private bool moving = false;

    private const int late = 50;
    
    void Start () {
        Application.runInBackground = true;
        cmd_ptr["ppo"] = cmd_ppo;
        cmd_ptr["plv"] = cmd_plv;
        cmd_ptr["pin"] = cmd_pin;
        cmd_ptr["pex"] = cmd_pex;
        cmd_ptr["pbc"] = cmd_pbc;
        cmd_ptr["pfk"] = cmd_pfk;
        cmd_ptr["pdr"] = cmd_pdr;
        cmd_ptr["pgt"] = cmd_pgt;
        cmd_ptr["pdi"] = cmd_pdi;
    }

    private void cmd_pdi(string[] cmd)
    {
        if (cmd.Length == 2)
        {
            try
            {
                int id = int.Parse(cmd[1]);
                field.killPlayer(player.GetId());
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

    private void cmd_pgt(string[] cmd)
    {
        if (cmd.Length == 3)
        {
            try
            {
                int id = int.Parse(cmd[1]);
                int res = int.Parse(cmd[2]);
                
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

    private void cmd_pdr(string[] cmd)
    {
        if (cmd.Length == 3)
        {
            try
            {
                int id = int.Parse(cmd[1]);
                int res = int.Parse(cmd[2]);
                
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

    private void cmd_pfk(string[] cmd)
    {
        if (cmd.Length == 2)
        {
            try
            {
                int id = int.Parse(cmd[1]);
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

    private void cmd_pbc(string[] cmd)
    {
        if (cmd.Length == 3)
        {
            try
            {
                int id = int.Parse(cmd[1]);
                int bc = int.Parse(cmd[2]);
                //TODO Something
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

    private void cmd_pex(string[] cmd)
    {
        if (cmd.Length == 2)
        {
            try
            {
                int id = int.Parse(cmd[1]);
                field.killPlayer(player.GetId());
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

    private void cmd_pin(string[] cmd)
    {
        if (cmd.Length == 11)
        {
            try
            {
                int id = int.Parse(cmd[1]);
                int x = int.Parse(cmd[2]);
                int y = int.Parse(cmd[3]);
                Inventory items = new Inventory();
                items.SetFood(int.Parse(cmd[4]));
                items.SetLinemate(int.Parse(cmd[5]));
                items.SetDeraumere(int.Parse(cmd[6]));
                items.SetSibur(int.Parse(cmd[7]));
                items.SetMendiane(int.Parse(cmd[8]));
                items.SetPhiras(int.Parse(cmd[9]));
                items.SetThystame(int.Parse(cmd[10]));
                player.SetItems(items);
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

    private void cmd_plv(string[] cmd)
    {
        if (cmd.Length == 3)
        {
            try
            {
                int id = int.Parse(cmd[1]);
                int lv = int.Parse(cmd[2]);
                player.SetLevel(lv);
                Behaviour halo = player.player.GetComponent("Halo") as Behaviour;
                if (halo != null)
                {
                    halo.enabled = false;
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

    private void cmd_ppo(string[] cmd)
    {
        if (cmd.Length == 5)
        {
            try
            {
                int id = int.Parse(cmd[1]);
                int x = int.Parse(cmd[2]);
                int y = int.Parse(cmd[3]);
                int o = int.Parse(cmd[4]);
                float lastX = player.GetX();
                float lastY = player.GetY();
                float lastO = player.GetOrientation();
                moving = true;
                SetPos(x, y, o);
                StartCoroutine(move(field.GetTile(x, y), lastO, lastO != player.GetOrientation(),
                    (lastX != player.GetX() || lastY != player.GetY())));
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

    private IEnumerator move(GameObject tile, float lastO, bool turn, bool forward)
    {
        float delta = 0;
        float action = 10f;
        if (turn)
        {
            if (field.commands.Count < late)
            {
                for (float i = 0; i < action / field.freq; i += (delta = Time.deltaTime))
                {
                    if (i > action / field.freq)
                        delta -= (i - action / field.freq);
                    if (lastO + 1 == player.GetOrientation() || (lastO == 4 && player.GetOrientation() == 1))
                        player.player.transform.Rotate(Vector3.up * (90 / (action / field.freq) * delta));
                    else
                        player.player.transform.Rotate(Vector3.down * (90 / (action / field.freq) * delta));
                    yield return new WaitForEndOfFrame();
                }
            }
            lastO = player.GetOrientation();
            transform.rotation = Quaternion.Euler(0, (lastO - 1) * 90, 0);
        }
        if (forward)
        {
            if (field.commands.Count < late)
            {
                for (float i = 0; i < action / field.freq; i += (delta = Time.deltaTime))
                {
                    if (i > action / field.freq)
                        delta -= (i - action / field.freq);
                    if (player.GetOrientation() == 1)
                        transform.position += Vector3.back * (field.blockZ / (action / field.freq) * delta);
                    else if (player.GetOrientation() == 2)
                        transform.position += Vector3.left * (field.blockX / (action / field.freq) * delta);
                    if (player.GetOrientation() == 3)
                        transform.position += Vector3.forward * (field.blockZ / (action / field.freq) * delta);
                    else if (player.GetOrientation() == 4)
                        transform.position += Vector3.right * (field.blockX / (action / field.freq) * delta);
                    if (player.player.transform.position.x < field.minX)
                    {
                        player.player.transform.position =
                            new Vector3(field.maxX,
                            player.player.transform.position.y,
                            player.player.transform.position.z);
                    }
                    else if (player.player.transform.position.x > field.maxX)
                    {
                        player.player.transform.position =
                            new Vector3(field.minX,
                            player.player.transform.position.y,
                            player.player.transform.position.z);
                    }
                    if (player.player.transform.position.z < field.minZ)
                    {
                        player.player.transform.position =
                            new Vector3(player.player.transform.position.x,
                            player.player.transform.position.y,
                            field.maxZ);
                    }
                    else if (player.player.transform.position.z > field.maxZ)
                    {
                        player.player.transform.position =
                            new Vector3(player.player.transform.position.x,
                            player.player.transform.position.y,
                            field.minZ);
                    }
                    yield return new WaitForEndOfFrame();
                }
            }
            player.player.transform.position =
                        new Vector3(
                            tile.transform.position.x - tile.transform.localScale.x / 2 + player.randX,
                            tile.transform.position.y + tile.transform.localScale.y / 2 + transform.localScale.y,
                            tile.transform.position.z - tile.transform.localScale.z / 2 + player.randZ);
        }
        moving = false;
        yield return null;
    }
    
    void FixedUpdate() {

        try
        {
            if (moving == false && field.commands.Count > 0)
            {
                int len = -1;
                bool end = false;
                while (!end && ++len < field.commands.Count)
                {
                    string[] splitCmd = field.commands[len].Split(' ');
                    if (splitCmd.Length > 1)
                    {
                        int id = int.Parse(splitCmd[1]);
                        if (cmd_ptr.ContainsKey(splitCmd[0]) && id == player.GetId())
                        {
                            cmd_ptr[splitCmd[0]](splitCmd);
                        }
                        else
                        {
                            end = true;
                        }
                    }
                }
                for (int i = 0; i < len; ++i)
                {
                    field.commands.RemoveAt(0);
                }
            }
        }
        catch (Exception e)
        {
            Debug.LogError(e.Message);
        }
    }


    private void LateUpdate()
    {
        try
        {
            player.updateLevel();
            if (field.Cam != null && player.canvas != null)
                player.canvas.transform.LookAt(field.Cam.transform);
        }
        catch (Exception e)
        {
        }
    }

    public void SetPlayer(Player _player)
    {
        player = _player;
    }

    public void SetPos(int x, int y, int o)
    {
        if (player != null)
        {
            player.SetX(x);
            player.SetY(y);
            player.SetOrientation(o);
        }
    }
}
