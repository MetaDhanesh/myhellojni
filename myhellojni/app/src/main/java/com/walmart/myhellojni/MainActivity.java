package com.walmart.myhellojni;

import androidx.appcompat.app.AppCompatActivity;
import android.util.Log;

import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    @Override    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        TextView tv = (TextView)findViewById(R.id.hello_txt);

        jniImpl c = new jniImpl(0);
        jniImpl d = new jniImpl(10);

        System.out.println("c=" + c + ", d=" + d.getVal());

        tv.setText("c=" + c + ", d=" + d.getVal());

        try {
            Thread.sleep(5000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        c.add(4);
        c.decrement();
        System.out.println("c=" + c + ", d=" + d.getVal());

        tv.setText("c=" + c + ", d=" + d.getVal());

        try {
            Thread.sleep(5000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        c.subtract(-2);
        c.increment();
        System.out.println("c=" + c + ", d=" + d.getVal());

        tv.setText("c=" + c + ", d=" + d.getVal());

        try {
            Thread.sleep(5000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        d.decrement();
        System.out.println("c=" + c + ", d=" + d.getVal());

        tv.setText("c=" + c + ", d=" + d.getVal());
    }


}