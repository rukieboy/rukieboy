package rukieboy.test.topwindowview;

import android.app.Service;
import android.content.Context;
import android.content.Intent;
import android.graphics.PixelFormat;
import android.os.IBinder;
import android.view.Gravity;
import android.view.LayoutInflater;
import android.view.MotionEvent;
import android.view.View;
import android.view.View.OnTouchListener;
import android.view.WindowManager;
import android.widget.Toast;

import android.widget.TextView;
import android.util.TypedValue;
import android.graphics.Color;
import android.view.Gravity;
import android.widget.ImageView;
import android.widget.LinearLayout;;


public class AlwaysTopServiceTouch extends Service {
	private View mView;
	private WindowManager mManager;
	private WindowManager.LayoutParams mParams;

	private float mTouchX, mTouchY;
	private int mViewX, mViewY;

	private boolean isMove = false;
	private boolean isClicked = false;
	
	private TextView mPopupView;//rukieboy
	
	private static ImageView mImgView1;
	private static ImageView mImgView2;
	//private WindowManager.LayoutParams mParams;//rukieboy 
	
	private OnTouchListener mViewTouchListener = new OnTouchListener() {
		@Override
		public boolean onTouch(View v, MotionEvent event) {

			switch (event.getAction()) {
			case MotionEvent.ACTION_DOWN:
				isMove = false;

				mTouchX = event.getRawX();
				mTouchY = event.getRawY();
				mViewX = mParams.x;
				mViewY = mParams.y;

				break;

			case MotionEvent.ACTION_UP:
				if(!isClicked)
				{
					if (!isMove) {
						isClicked = true;
						mImgView1.setImageResource(R.drawable.ic_launcher_b);
					Toast.makeText(getApplicationContext(), "Off!",
							Toast.LENGTH_SHORT).show();
					}
					
					
				}
				else
				{
					if (!isMove) {
						isClicked = false;
						mImgView1.setImageResource(R.drawable.ic_launcher);
						Toast.makeText(getApplicationContext(), "On!",
								Toast.LENGTH_SHORT).show();
						}
					
					
					//mImgView1 = (ImageView) v.findViewById(R.id.image);
					//mImgView1.setImageResource(R.id.image_b);
					//v.setBackgroundResource(R.id.image_b);
					
					
					
				}
				break;

			case MotionEvent.ACTION_MOVE:
				isMove = true;

				int x = (int) (event.getRawX() - mTouchX);
				int y = (int) (event.getRawY() - mTouchY);

				final int num = 5;
				if ((x > -num && x < num) && (y > -num && y < num)) {
					isMove = false;
					break;
				}

				/**
				 * mParams.gravity�� ���� ��ȣ ����
				 * 
				 * LEFT : x�� +
				 * 
				 * RIGHT : x�� -
				 * 
				 * TOP : y�� +
				 * 
				 * BOTTOM : y�� -
				 */
				mParams.x = mViewX + x;
				mParams.y = mViewY + y;

				mManager.updateViewLayout(mImgView1, mParams);

				break;
			}

			return true;
		}
	};

	@Override
	public void onCreate() {
		super.onCreate();

		
		LayoutInflater mInflater = (LayoutInflater) getSystemService(Context.LAYOUT_INFLATER_SERVICE);
		//mView = mInflater.inflate(R.layout.always_on_top_view_touch, null);
		
		
		//mView.setOnTouchListener(mViewTouchListener);
		
		//mImgView1 = (ImageView) mView.findViewById(R.id.image);
		//mImgView2 = (ImageView) mView.findViewById(R.id.image_b);
		//ImageView imagebyCode = new ImageView(this);
		mImgView1 = new ImageView(this);
		mImgView1.setImageResource(R.drawable.ic_launcher_b);
		mImgView1.setOnTouchListener(mViewTouchListener);
		//mImgView1  =(ImageView) mInflater.inflate(R.drawable.ic_launcher_b, null);
		
		mParams = new WindowManager.LayoutParams(
				WindowManager.LayoutParams.WRAP_CONTENT,
				WindowManager.LayoutParams.WRAP_CONTENT,
				WindowManager.LayoutParams.TYPE_PHONE,
				WindowManager.LayoutParams.FLAG_NOT_FOCUSABLE,
				PixelFormat.TRANSLUCENT);
		mParams.gravity = Gravity.TOP | Gravity.LEFT;

		mManager = (WindowManager) getSystemService(WINDOW_SERVICE);
		
		mManager.addView(mImgView1, mParams);
		
		//mManager.addView(mView, mParams);
		
		
    }


	@Override
	public void onDestroy() {
		super.onDestroy();
		if (mView != null) {
			mManager.removeView(mView);
			mView = null;
		}
	}

	@Override
	public IBinder onBind(Intent arg0) {
		return null;
	}

}
