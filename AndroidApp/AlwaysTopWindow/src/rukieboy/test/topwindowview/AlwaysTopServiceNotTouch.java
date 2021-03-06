package rukieboy.test.topwindowview;

import android.app.Service;
import android.content.Context;
import android.content.Intent;
import android.graphics.PixelFormat;
import android.os.IBinder;
import android.view.LayoutInflater;
import android.view.View;
import android.view.WindowManager;
import android.widget.TextView;
import android.util.TypedValue;
import android.graphics.Color;
import android.view.Gravity;

public class AlwaysTopServiceNotTouch extends Service {
	//private View mView;
	private WindowManager mManager;
	
	private TextView mPopupView;//rukieboy
	private WindowManager.LayoutParams mParams;//rukieboy 
	@Override
	public void onCreate() {
		super.onCreate();

		mPopupView = new TextView(this);   //rukieboy
		mPopupView.setText("always top view"); 
		mPopupView.setTextSize(TypedValue.COMPLEX_UNIT_SP, 18);
		mPopupView.setTextColor(Color.BLUE);
		 mPopupView.setBackgroundColor(Color.argb(127, 0, 255, 255));
		} 
		//LayoutInflater mInflater = (LayoutInflater) getSystemService(Context.LAYOUT_INFLATER_SERVICE);
		//mView = mInflater.inflate(R.layout.always_on_top_view_not_touch, null);
		/*
		
		 mParams = new WindowManager.LayoutParams(
            WindowManager.LayoutParams.WRAP_CONTENT,
            WindowManager.LayoutParams.WRAP_CONTENT,
            WindowManager.LayoutParams.TYPE_PHONE,//�׻� �� ����. ��ġ �̺�Ʈ ���� �� ����.
            WindowManager.LayoutParams.FLAG_NOT_FOCUSABLE,  //��Ŀ���� ������ ����
            PixelFormat.TRANSLUCENT);                                        //����
        mParams.gravity = Gravity.LEFT | Gravity.TOP;                   //���� ��ܿ� ��ġ�ϰ� ��.
        
        mManager = (WindowManager) getSystemService(WINDOW_SERVICE);  //������ �Ŵ���
        mManager.addView(mPopupView, mParams);      //�����쿡 �� �ֱ�. permission �ʿ�.
    }
		*/
/*
		WindowManager.LayoutParams mParams = new WindowManager.LayoutParams(
				WindowManager.LayoutParams.WRAP_CONTENT,
				WindowManager.LayoutParams.WRAP_CONTENT,
				//set always top mode
				WindowManager.LayoutParams.TYPE_SYSTEM_OVERLAY,
				//do not get touch event
				WindowManager.LayoutParams.FLAG_WATCH_OUTSIDE_TOUCH,
				PixelFormat.TRANSLUCENT); //transparents

		mManager = (WindowManager) getSystemService(WINDOW_SERVICE);
		mManager.addView(mView, mParams);
	}
*/
	@Override
	public void onDestroy() {
		super.onDestroy();

		if (mPopupView != null) {
			mManager.removeView(mPopupView);
			mPopupView = null;
		}
	}

	@Override
	public IBinder onBind(Intent arg0) {
		return null;
	}

}
