import javax.swing.*;
import java.awt.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Numericanvas extends JPanel
{
    private List<List<Coordinate>> coordinates = new ArrayList<>(2);
    List<Color> colors = Arrays.asList(Color.BLACK, Color.RED);

    @Override
    public void paintComponent(Graphics g) {
        super.paintComponent(g);
        System.out.println("Painting " + coordinates.size() + " lines");
        for (int j = 0; j < coordinates.size(); j++)
        {
            List<Coordinate> coordinates = this.coordinates.get(j);
            g.setColor(colors.get(j));
            for (int i = 1; i < coordinates.size(); i++)
                g.drawLine(coordinates.get(i - 1).roundX(), getSize().height - coordinates.get(i - 1).roundY(),
                        coordinates.get(i).roundX(), getSize().height - coordinates.get(i).roundY());
        }
    }

    public void drawData(List<Coordinate> coordinates) {
        this.coordinates.clear();
        this.coordinates.add(coordinates);
        repaint();
    }

    public void drawMultipleData(List<List<Coordinate>> coordinates) {
        this.coordinates = coordinates;
        repaint();
    }
}
