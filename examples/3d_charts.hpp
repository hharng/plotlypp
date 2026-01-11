#include <string>
#include <utility>
#include <vector>

#include <plotlypp/plot.hpp>
#include <plotlypp/traces/scatter3d.hpp>
#include <plotlypp/traces/surface.hpp>

namespace plotlypp {

// https://plotly.com/javascript/3d-surface-plots/
Figure multiple3DSurfacePlots() {
    std:: : vector<std::vector<double>> z1 = {
                {8.83, 8.89, 8.81, 8.87, 8.9, 8.87},  {8.89, 8.94, 8.85, 8.94, 8.96, 8.92},
                {8.84, 8.9, 8.82, 8.92, 8.93, 8.91},  {8.79, 8.85, 8.79, 8.9, 8.94, 8.92},
                {8.79, 8.88, 8.81, 8.9, 8.95, 8.92},  {8.8, 8.82, 8.78, 8.91, 8.94, 8.92},
                {8.75, 8.78, 8.77, 8.91, 8.95, 8.92}, {8.8, 8.8, 8.77, 8.91, 8.95, 8.94},
                {8.74, 8.81, 8.76, 8.93, 8.98, 8.99}, {8.89, 8.99, 8.92, 9.1, 9.13, 9.11},
                {8.97, 8.97, 8.91, 9.09, 9.11, 9.11}, {9.04, 9.08, 9.05, 9.25, 9.28, 9.27},
                {9, 9.01, 9, 9.2, 9.23, 9.2},         {8.99, 8.99, 8.98, 9.18, 9.2, 9.19},
                {8.93, 8.97, 8.97, 9.18, 9.2, 9.18}};

    std::vector<std::vector<double>> z2;
    for (const auto& row : z1) {
        std::vector<double> z2_row;
        for (double v : row) {
            z2_row.push_back(v + 1);
        }
        z2.push_back(std::move(z2_row));
    }

    std::vector<std::vector<double>> z3;
    for (const auto& row : z1) {
        std::vector<double> z3_row;
        for (double v : row) {
            z3_row.push_back(v - 1);
        }
        z3.push_back(std::move(z3_row));
    }

    auto trace1 = Surface().z(std::move(z1));
    auto trace2 = Surface().z(std::move(z2)).showscale(false).opacity(0.9);
    auto trace3 = Surface().z(std::move(z3)).showscale(false).opacity(0.9);
    return Figure().addTraces(std::vector<Trace>{std::move(trace1), std::move(trace2), std::move(trace3)});
}

// https://plotly.com/javascript/3d-mesh/
// https://plotly.com/python/3d-mesh/

Figure meshCube() {
    std::vector<double> intensity = {0,
                                     0.14285714285714285,
                                     0.2857142857142857,
                                     0.42857142857142855,
                                     0.5714285714285714,
                                     0.7142857142857143,
                                     0.8571428571428571,
                                     1};
    std::vector<std::pair<double, std::string>> colorscale = {
        {0, "rgb(255, 0, 255)"}, {0.5, "rgb(0, 255, 0)"}, {1, "rgb(0, 0, 255)"}};
    auto trace = Mesh3d()
                     .x(std::vector{0, 0, 1, 1, 0, 0, 1, 1})
                     .y(std::vector{0, 1, 1, 0, 0, 1, 1, 0})
                     .z(std::vector{0, 0, 0, 0, 1, 1, 1, 1})
                     .i(std::vector{7, 0, 0, 0, 4, 4, 6, 6, 4, 0, 3, 2})
                     .j(std::vector{3, 4, 1, 2, 5, 6, 5, 2, 0, 1, 6, 3})
                     .k(std::vector{0, 7, 2, 3, 6, 7, 1, 1, 5, 5, 7, 6})
                     .intensity(std::move(intensity))
                     .colorscale(std::move(colorscale));
    return Figure().addTrace(std::move(trace));
}

/*
//

//
https://plotly.com/javascript/3d-mesh/
https://plotly.com/python/3d-mesh/
3D Mesh Cube

var intensity = [0, 0.14285714285714285, 0.2857142857142857,
0.42857142857142855, 0.5714285714285714, 0.7142857142857143, 0.8571428571428571,
1];

var data = [{
    type: "mesh3d",
    x: [0, 0, 1, 1, 0, 0, 1, 1],
    y: [0, 1, 1, 0, 0, 1, 1, 0],
    z: [0, 0, 0, 0, 1, 1, 1, 1],
    i: [7, 0, 0, 0, 4, 4, 6, 6, 4, 0, 3, 2],
    j: [3, 4, 1, 2, 5, 6, 5, 2, 0, 1, 6, 3],
    k: [0, 7, 2, 3, 6, 7, 1, 1, 5, 5, 7, 6],
    intensity: intensity,
    colorscale: [
      [0, 'rgb(255, 0, 255)'],
      [0.5, 'rgb(0, 255, 0)'],
      [1, 'rgb(0, 0, 255)']
    ]
  }
];

Plotly.newPlot('myDiv', data, {});

    go.Mesh3d(
        # 8 vertices of a cube
        x=[0, 0, 1, 1, 0, 0, 1, 1],
        y=[0, 1, 1, 0, 0, 1, 1, 0],
        z=[0, 0, 0, 0, 1, 1, 1, 1],
        colorbar=dict(title=dict(text='z')),
        colorscale=[[0, 'gold'],
                    [0.5, 'mediumturquoise'],
                    [1, 'magenta']],
        # Intensity of each vertex, which will be interpolated and color-coded
        intensity = np.linspace(0, 1, 8, endpoint=True),
        # i, j and k give the vertices of triangles
        i = [7, 0, 0, 0, 4, 4, 6, 6, 4, 0, 3, 2],
        j = [3, 4, 1, 2, 5, 6, 5, 2, 0, 1, 6, 3],
        k = [0, 7, 2, 3, 6, 7, 1, 1, 5, 5, 7, 6],
        name='y',
        showscal
*/

// https://plotly.com/javascript/3d-line-plots/

Figure 3dLineSpiral() {
    int point_count = 3142;
    std::vector<double> x;
    std::vector<double> y;
    std::vector<double> z;
    std::vector<double> c;
    for (int i = 0; i < point_count; i++) {
        double r = i * (point_count - i);
        x.push_back(r * std::cos(i / 30));
        y.push_back(r * std::sin(i / 30));
        z.push_back(i);
        c.push_back(i);
    }
    return Figure().addTrace(Scatter3d()
                                 .x(std::move(x))
                                 .y(std::move(y))
                                 .z(std::move(z))
                                 .opacity(0.7)
                                 .line(Scatter3d::Line().width(10).color(std::move(c)).colorscale("Viridis")));
}

// https://plotly.com/python/3d-scatter-plots/

} // namespace plotlypp

/*


//
https://plotly.com/python/3d-scatter-plots/
3D Scatter Plot with Colorscaling and Marker Styling
# Helix equation
t = np.linspace(0, 20, 100)
x, y, z = np.cos(t), np.sin(t), t

fig = go.Figure(data=[go.Scatter3d(
    x=x,
    y=y,
    z=z,
    mode='markers',
    marker=dict(
        size=12,
        color=z,                # set color to an array/list of desired values
        colorscale='Viridis',   # choose a colorscale
        opacity=0.8
    )
)])

# tight layout
fig.update_layout(margin=dict(l=0, r=0, b=0, t=0))

//
https://plotly.com/python/3d-volume-plots/
X, Y, Z = np.mgrid[-8:8:40j, -8:8:40j, -8:8:40j]
values = np.sin(X*Y*Z) / (X*Y*Z)

fig = go.Figure(data=go.Volume(
    x=X.flatten(),
    y=Y.flatten(),
    z=Z.flatten(),
    value=values.flatten(),
    isomin=0.1,
    isomax=0.8,
    opacity=0.1, # needs to be small to see through all surfaces
    surface_count=17, # needs to be a large number for good volume rendering
    ))

//
https://plotly.com/python/3d-isosurface-plots/
Removing caps when visualizing isosurfaces
X, Y, Z = np.mgrid[-5:5:40j, -5:5:40j, -5:5:40j]

# ellipsoid
values = X * X * 0.5 + Y * Y + Z * Z * 2

fig = go.Figure(data=go.Isosurface(
    x=X.flatten(),
    y=Y.flatten(),
    z=Z.flatten(),
    value=values.flatten(),
    isomin=10,
    isomax=40,
    caps=dict(x_show=False, y_show=False)
    ))

//
modifying number of isosurfaces
X, Y, Z = np.mgrid[-5:5:40j, -5:5:40j, -5:5:40j]

# ellipsoid
values = X * X * 0.5 + Y * Y + Z * Z * 2

fig = go.Figure(data=go.Isosurface(
    x=X.flatten(),
    y=Y.flatten(),
    z=Z.flatten(),
    value=values.flatten(),
    isomin=10,
    isomax=50,
    surface_count=5, # number of isosurfaces, 2 by default: only min and max
    colorbar_nticks=5, # colorbar ticks correspond to isosurface values
    caps=dict(x_show=False, y_show=False)
    ))

//

https://plotly.com/python/3d-bubble-charts/
Bubble Chart Sized by a Variable

planets = ['Mercury', 'Venus', 'Earth', 'Mars', 'Jupiter', 'Saturn', 'Uranus',
'Neptune', 'Pluto'] planet_colors = ['rgb(135, 135, 125)', 'rgb(210, 50, 0)',
'rgb(50, 90, 255)', 'rgb(178, 0, 0)', 'rgb(235, 235, 210)', 'rgb(235, 205,
130)', 'rgb(55, 255, 217)', 'rgb(38, 0, 171)', 'rgb(255, 255, 255)']
distance_from_sun = [57.9, 108.2, 149.6, 227.9, 778.6, 1433.5, 2872.5, 4495.1,
5906.4] density = [5427, 5243, 5514, 3933, 1326, 687, 1271, 1638, 2095] gravity
= [3.7, 8.9, 9.8, 3.7, 23.1, 9.0, 8.7, 11.0, 0.7] planet_diameter = [4879,
12104, 12756, 6792, 142984, 120536, 51118, 49528, 2370]

# Create trace, sizing bubbles by planet diameter
fig = go.Figure(data=go.Scatter3d(
    x = distance_from_sun,
    y = density,
    z = gravity,
    text = planets,
    mode = 'markers',
    marker = dict(
        sizemode = 'diameter',
        sizeref = 750, # info on sizeref:
https://plotly.com/python/reference/scatter/#scatter-marker-sizeref size =
planet_diameter, color = planet_colors,
        )
))

fig.update_layout(
    width=800,
    height=800,
    title=dict(text="Planets!"),
    scene=dict(
        xaxis=dict(
            title=dict(
                text="Distance from Sun",
                font=dict(
                    color="white"
                )
            )
        ),
        yaxis=dict(
            title=dict(
                text="Density",
                font=dict(
                    color="white"
                )
            )
        ),
        zaxis=dict(
            title=dict(
                text="Gravity",
                font=dict(
                    color="white"
                )
            )
        ),
        bgcolor="rgb(20, 24, 54)"
    )
)

//
https://plotly.com/python/3d-subplots/
# Initialize figure with 4 3D subplots
fig = make_subplots(
    rows=2, cols=2,
    specs=[[{'type': 'surface'}, {'type': 'surface'}],
           [{'type': 'surface'}, {'type': 'surface'}]])

# Generate data
x = np.linspace(-5, 80, 10)
y = np.linspace(-5, 60, 10)
xGrid, yGrid = np.meshgrid(y, x)
z = xGrid ** 3 + yGrid ** 3

# adding surfaces to subplots.
fig.add_trace(
    go.Surface(x=x, y=y, z=z, colorscale='Viridis', showscale=False),
    row=1, col=1)

fig.add_trace(
    go.Surface(x=x, y=y, z=z, colorscale='RdBu', showscale=False),
    row=1, col=2)

fig.add_trace(
    go.Surface(x=x, y=y, z=z, colorscale='YlOrRd', showscale=False),
    row=2, col=1)

fig.add_trace(
    go.Surface(x=x, y=y, z=z, colorscale='YlGnBu', showscale=False),
    row=2, col=2)

fig.update_layout(
    title_text='3D subplots with different colorscales',
    height=800,
    width=800
)

*/
