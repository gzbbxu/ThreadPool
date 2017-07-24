package com.example.test;

import android.net.http.HttpResponseCache;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {

    // Used to load the 'native-lib' library on application startup.
    int thradHadnler  = 0;
    private int[] array = new int[]{1,2,3};
    private Button btn1 ,btn2;
    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        btn1 = (Button) findViewById(R.id.btn1);
        btn1.setOnClickListener(this);
        btn2= (Button) findViewById(R.id.btn2);
        btn2.setOnClickListener(this);
        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.sample_text);
        tv.setText(stringFromJNI());
        HttpResponseCache cacehl;

       /* thradHadnler = createThradPool();
        Log.i("zhouke","threadHandler:"+thradHadnler);*/
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();

    public native  String sayHello();

    public native  int createThradPool();

    public native void threadAdd(int handler, int [] array);

    public native  void thradDestory(int handler);

    @Override
    public void onClick(View view) {
        switch (view.getId()){
            case R.id.btn1:
                //测试线程池int数组
                if(thradHadnler==0){
                    thradHadnler = createThradPool();
                }
                threadAdd(thradHadnler,array);
                break;
            case R.id.btn2:
                new Thread(){
                    @Override
                    public void run() {
                        long t1 = System.currentTimeMillis();
                        thradDestory(thradHadnler);
                        Log.i("System.out.c",(System.currentTimeMillis()-t1)+":销毁时间");
                        thradHadnler = 0 ;
                    }
                }.start();

                break;
        }
    }
}
