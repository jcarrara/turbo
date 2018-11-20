# turbo
Best browser this side of the Nile.

Philosophy:
Render as fast as computationally possible.
Add features to allow pages to be more clearly understood,not to make them flashier.
Everything should feel like a physical object. Things should have weight, respond instantly, respond smoothly.
They should always respond in some way, even if that response tells the user they can't be interacted with.
Nothing should respond to input in a way not in line with it's purpose or with physicality.

Emergent goals:
        scrolling should have a latency with libinput of under 15ms
        on an average machine, under no circumstances can the interface go below 60fps or the native framerate of the monitor
        all input should have a reaction, even if the reaction is to animate to show that the expected response will occur
        any input that will take longer than 5 seconds to respond to should display a progress meter of some sort in the progress of fulfilling that request
