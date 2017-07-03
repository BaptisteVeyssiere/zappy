using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CameraController : MonoBehaviour {


    private float OSpeed = -80.0F;
    private float ASpeed = 80.0F;

    private float ordinate = 0.0F;
    private float absciss = 0.0F;

    public float speed = 30.0F;

    [SerializeField]
    private GameObject menu;

    [SerializeField]
    private GameObject board;

    void Start () {
        field.Cam = GetComponent<Camera>();
        Cursor.visible = true;
        Cursor.lockState = CursorLockMode.None;
    }
	
	void Update () {
        
        if (Input.GetKeyDown(KeyCode.Escape) && !board.activeSelf)
        {
            if (Cursor.lockState == CursorLockMode.Locked)
            {
                Cursor.lockState = CursorLockMode.None;
                Cursor.visible = true;
                menu.SetActive(true);
            }
            else
            {
                menu.SetActive(false);
                Cursor.lockState = CursorLockMode.Locked;
                Cursor.visible = false;
            }
        }
        if (Input.GetKeyDown(KeyCode.Tab) && !menu.activeSelf)
        {
            if (Cursor.lockState == CursorLockMode.Locked)
            {
                Cursor.lockState = CursorLockMode.None;
                Cursor.visible = true;
                board.SetActive(true);
            }
            else
            {
                board.SetActive(false);
                Cursor.lockState = CursorLockMode.Locked;
                Cursor.visible = false;
            }
        }
        if (Input.GetKey(KeyCode.LeftShift))
        {
            speed = 60.0F;
        }
        else
        {
            speed = 30.0F;
        }
        if (field.camState == 0 && Cursor.lockState == CursorLockMode.Locked)
        {
            float x = Input.GetAxis("Horizontal") * Time.deltaTime * speed;
            float z = Input.GetAxis("Vertical") * Time.deltaTime * speed;
            float y = 0f;
            if (Input.GetKey(KeyCode.Space))
            {
                y = 1 * Time.deltaTime * speed;
            }
            ordinate += OSpeed * Input.GetAxis("Mouse Y") * Time.deltaTime;
            absciss += ASpeed * Input.GetAxis("Mouse X") * Time.deltaTime;

            ordinate = Mathf.Clamp(ordinate, -90.0f, 90.0f);

            transform.Translate(0, 0, z);
            transform.Translate(x, 0, 0);
            transform.Translate(0, y, 0);
 
            transform.rotation = Quaternion.Euler(ordinate, absciss, 0.0f);
            
        }
    }

    private void LateUpdate()
    {
        if (Input.GetKeyDown(KeyCode.Y) && Cursor.lockState == CursorLockMode.Locked)
        {
            if (field.camState != 2)
            {
                field.clearPlayerFollow();
                GameObject center = field.GetCamOnField();
                if (center != null)
                {
                    transform.position = center.transform.position;
                    transform.position = new Vector3(transform.position.x, transform.position.y + 2 * (field.width / 2 * center.transform.localScale.y), transform.position.z - 2 * (field.height / 2 * center.transform.localScale.z));
                    transform.LookAt(center.transform);
                }
                else
                {
                    transform.position = Vector3.zero;
                }
                field.camState = 2;
            }
            else
            {
                field.camState = 0;
            }
        }

        Player tmp = null;
        
        if (field.camState == 1 && field.playerId >= 0 && (tmp = field.playerFollow) != null)
        {
            transform.position = tmp.player.transform.position;
            transform.position = new Vector3(transform.position.x, transform.position.y + 5 * tmp.player.transform.localScale.y, transform.position.z - 5 * tmp.player.transform.localScale.z);
            transform.LookAt(tmp.player.transform);
        }
    }
}
