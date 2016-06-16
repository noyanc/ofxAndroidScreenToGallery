package cc.openframeworks.ofxaddons.ofxandroidscreentogallery;

import java.io.File;

import android.content.Intent;
import android.net.Uri;
import android.os.Environment;


public class OFXAndroidScreenToGallery extends cc.openframeworks.OFAndroidObject {

	public OFXAndroidScreenToGallery() {
	}
	
	
	@SuppressWarnings("unused")
	private String getPictureDirectoryPath() {
		return Environment.getExternalStoragePublicDirectory(Environment.DIRECTORY_PICTURES).getPath();
	}
	
	
	@SuppressWarnings("unused")
	private void addScreenshotToGallery(String filepath) {
	    Intent mediaScanIntent = new Intent(Intent.ACTION_MEDIA_SCANNER_SCAN_FILE);
	    File f = new File(filepath);
	    Uri contentUri = Uri.fromFile(f);
	    mediaScanIntent.setData(contentUri);
	    activity.sendBroadcast(mediaScanIntent);
	}

	@Override
	protected void appPause() {
		// TODO Auto-generated method stub
		
	}


	@Override
	protected void appResume() {
		// TODO Auto-generated method stub
		
	}


	@Override
	protected void appStop() {
		// TODO Auto-generated method stub
		
	}

}
