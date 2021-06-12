package ae_mc.remotecontrol;

import android.content.pm.ActivityInfo;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

enum MODE {tul, sparring};
public class MainActivity extends AppCompatActivity {
    private double redScore, blueScore;
    public static MODE mode = MODE.tul;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        setRequestedOrientation(ActivityInfo.SCREEN_ORIENTATION_SENSOR_LANDSCAPE);
        setup(mode);
    }

    public void setup(MODE mode) {
        View.OnClickListener listener = new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String command = ((Button) v).getText().toString();
                switch (v.getId()) {
                    case R.id.addBlue1:
                    case R.id.addBlue2:
                    case R.id.addBlue3:
                    case R.id.subBlue1:
                    case R.id.subBlue2:
                    case R.id.subBlue3:
                        blueScore = Double.parseDouble(String.format("%.2f", blueScore + Double.parseDouble(command)));

                        break;
                    case R.id.addRed1:
                    case R.id.addRed2:
                    case R.id.addRed3:
                    case R.id.subRed1:
                    case R.id.subRed2:
                    case R.id.subRed3:
                        redScore = Double.parseDouble(String.format("%.2f", redScore + Double.parseDouble(command)));
                        break;
                }
                updateScore();
            }
        };

        findViewById(R.id.addBlue1).setOnClickListener(listener);
        findViewById(R.id.addBlue2).setOnClickListener(listener);
        findViewById(R.id.addBlue3).setOnClickListener(listener);
        findViewById(R.id.subBlue1).setOnClickListener(listener);
        findViewById(R.id.subBlue2).setOnClickListener(listener);
        findViewById(R.id.subBlue3).setOnClickListener(listener);
        findViewById(R.id.addRed1).setOnClickListener(listener);
        findViewById(R.id.addRed2).setOnClickListener(listener);
        findViewById(R.id.addRed3).setOnClickListener(listener);
        findViewById(R.id.subRed1).setOnClickListener(listener);
        findViewById(R.id.subRed2).setOnClickListener(listener);
        findViewById(R.id.subRed3).setOnClickListener(listener);

        findViewById(R.id.resetBlue).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                blueScore = 100;
                updateScore();
            }
        });
        findViewById(R.id.resetRed).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                redScore = 100;
                updateScore();
            }
        });

        if (mode == MODE.sparring) {
            redScore = 0;
            blueScore = 0;
            findViewById(R.id.resetBlue).setVisibility(View.INVISIBLE);
            findViewById(R.id.resetRed).setVisibility(View.INVISIBLE);
            findViewById(R.id.subBlue3).setVisibility(View.VISIBLE);
            findViewById(R.id.subRed3).setVisibility(View.VISIBLE);
            findViewById(R.id.addBlue3).setVisibility(View.VISIBLE);
            findViewById(R.id.addRed3).setVisibility(View.VISIBLE);

            ((Button)findViewById(R.id.addBlue1)).setText("+1");
            ((Button)findViewById(R.id.addBlue2)).setText("+2");
            ((Button)findViewById(R.id.addBlue3)).setText("+3");
            ((Button)findViewById(R.id.subBlue1)).setText("-1");
            ((Button)findViewById(R.id.subBlue2)).setText("-2");
            ((Button)findViewById(R.id.subBlue3)).setText("+3");
            ((Button)findViewById(R.id.addRed1)).setText("+1");
            ((Button)findViewById(R.id.addRed2)).setText("+2");
            ((Button)findViewById(R.id.addRed3)).setText("+3");
            ((Button)findViewById(R.id.subRed1)).setText("-1");
            ((Button)findViewById(R.id.subRed2)).setText("-2");
            ((Button)findViewById(R.id.subRed3)).setText("-3");
        } else if (mode == MODE.tul) {
            redScore = 100;
            blueScore = 100;

            findViewById(R.id.resetBlue).setVisibility(View.VISIBLE);
            findViewById(R.id.resetRed).setVisibility(View.VISIBLE);
            findViewById(R.id.subBlue3).setVisibility(View.INVISIBLE);
            findViewById(R.id.subRed3).setVisibility(View.INVISIBLE);
            findViewById(R.id.addBlue3).setVisibility(View.INVISIBLE);
            findViewById(R.id.addRed3).setVisibility(View.INVISIBLE);

            ((Button)findViewById(R.id.addBlue1)).setText("-0.2");
            ((Button)findViewById(R.id.addBlue2)).setText("-0.5");
            ((Button)findViewById(R.id.subBlue1)).setText("+0.2");
            ((Button)findViewById(R.id.subBlue2)).setText("+0.5");
            ((Button)findViewById(R.id.addRed1)).setText("-0.2");
            ((Button)findViewById(R.id.addRed2)).setText("-0.5");
            ((Button)findViewById(R.id.subRed1)).setText("+0.2");
            ((Button)findViewById(R.id.subRed2)).setText("+0.5");
        }

        updateScore();
    }

    public void updateScore() {
        if ( ((Double)redScore).intValue() == redScore)
            ((TextView)findViewById(R.id.scoreRed)).setText(String.format("%d", (int)redScore));
        else
            ((TextView)findViewById(R.id.scoreRed)).setText(String.format("%.1f", redScore));

        if ( ((Double)blueScore).intValue()== blueScore)
            ((TextView)findViewById(R.id.scoreBlue)).setText(String.format("%d", (int)blueScore));
        else
            ((TextView)findViewById(R.id.scoreBlue)).setText(String.format("%.1f", blueScore));
    }
}
