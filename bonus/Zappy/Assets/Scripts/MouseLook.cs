using System;
using UnityEngine;

public class MouseLook : MonoBehaviour
{
    public float mouseSensitivity = 100.0f;
    public float clampAngle = 80.0f;

    private float Y = 0.0f;
    private float X = 0.0f;

    void Start()
    {
        Vector3 rotation = transform.localRotation.eulerAngles;
        Y = rotation.y;
        X = rotation.x;
    }

    void Update()
    {
        float mouseX = Input.GetAxis("Mouse X");
        float mouseY = -Input.GetAxis("Mouse Y");

        Y += mouseX * mouseSensitivity * Time.deltaTime;
        X += mouseY * mouseSensitivity * Time.deltaTime;

        X = Mathf.Clamp(X, -clampAngle, clampAngle);

        Quaternion localRotation = Quaternion.Euler(X, Y, 0.0f);
        transform.rotation = localRotation;
    }
}