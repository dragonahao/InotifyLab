package lab.sodino.inotifylab;

import java.io.File;

import android.app.Activity;
import android.os.Bundle;
import android.os.Environment;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;


public class MainActivity extends Activity implements OnClickListener{
	static {
		System.loadLibrary("Inotify");
	}
	private native void watch(String pathWatch);
//	private native void unwatch();
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Button btnWatch = (Button) findViewById(R.id.btnWatch);
        btnWatch.setOnClickListener(this);
        Button btnUnWatch = (Button) findViewById(R.id.btnUnWatch);
        btnUnWatch.setOnClickListener(this);
    }

	@Override
	public void onClick(View v) {
		switch(v.getId()){
		case R.id.btnWatch:
			watch(Environment.getExternalStorageDirectory().getPath() + File.separator + "oook.jpg");
			break;
		case R.id.btnUnWatch:
//			unwatch();
			break;
		}
	}
    
    
}
