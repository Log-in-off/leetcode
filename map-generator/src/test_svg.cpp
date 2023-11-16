#include "test_svg.h"

#include "svg.h"
#include <vector>
#include <cmath>
//#define _USE_MATH_DEFINES

#include "map_generator.h"


svg::Polyline CreateLine(const std::vector <svg::Point> &points) {
    svg::Polyline polyline;
    for (const auto & point: points)
    {
        polyline.AddPoint(point);
    }

    return polyline;
}

svg::Polyline CreateClosedLine(const std::vector <svg::Point> &points) {
    return CreateLine(points).AddPoint(points.front());
}


svg::Rectangle CreateRectangle(svg::Point center, double width, double height)
{
    svg::Rectangle rec;
    rec.SetCenter(center).SetWidth(width).SetHeight(height);
    return rec;
}

void testLines(std::ostream &out)
{
    using namespace svg;
    //using namespace shapes;
    using namespace std;   
    Color rgb = Rgb{100, 200, 255};

    std::vector<svg::Point> shape = {{0, 0}, {800, 0}, {800, 600}, {0, 600}};
    std::vector<svg::Point> room = {{50, 50}, {100, 50}, {100, 100}, {50, 100}};
    svg::Document doc;
    doc.Add(CreateClosedLine(shape).SetStrokeWidth(5)
                              .SetStrokeLineJoin(svg::StrokeLineJoin::ROUND)
                              .SetStrokeLineCap(svg::StrokeLineCap::ROUND)
                              .SetFillColor("green")
                              .SetStrokeColor("green"));
    
    doc.Add(CreateRectangle({130, 200}, 40, 30).SetStrokeWidth(5)
                              .SetStrokeLineJoin(svg::StrokeLineJoin::ROUND)
                              .SetStrokeLineCap(svg::StrokeLineCap::ROUND)
                              .SetFillColor("none")
                              .SetStrokeColor(rgb));
                              

    doc.Add(CreateClosedLine(room).SetStrokeWidth(5)
                              .SetStrokeLineJoin(svg::StrokeLineJoin::ROUND)
                              .SetStrokeLineCap(svg::StrokeLineCap::ROUND)
                              .SetFillColor("none")
                              .SetStrokeColor(rgb));

    doc.Render(out);
}

void testRooms(std::ostream &out)
{
    using namespace svg;
    //using namespace shapes;
    using namespace std;   
    Color rgb = Rgb{100, 200, 255};
    double width = 200;
    double height = 150;

    Map map(width, height);
    map.generate(60);


    svg::Document doc;
    doc.Add(CreateRectangle({0, 0}, width, height).SetStrokeWidth(5)
                              .SetStrokeLineJoin(svg::StrokeLineJoin::ROUND)
                              .SetStrokeLineCap(svg::StrokeLineCap::ROUND)
                              .SetFillColor("green")
                              .SetStrokeColor("green"));
    
    for(auto it = map.beginRooms(); it != map.endRooms(); it++)
    {
        double x = it->x;
        double y = it->y;
        double w = it->w;
        double h = it->h;
        doc.Add(CreateRectangle({x, y}, w, h).SetStrokeWidth(1)
                              .SetStrokeLineJoin(svg::StrokeLineJoin::ROUND)
                              .SetStrokeLineCap(svg::StrokeLineCap::ROUND)
                              .SetFillColor("none")
                              .SetStrokeColor(rgb));                              

        
    }    

    doc.Render(out);
}